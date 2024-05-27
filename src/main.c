/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void check_monster(data_t *data)
{
    for (int i = 0; i < 100; i++)
        if (data->ennemies->slime[i]->is_alive == true)
            display_slime(data);
        else
            spawn_slime(data);
    for (int i = 0; i < 10; i++)
        if (data->ennemies->skeleton[i]->is_alive == true)
            display_skeleton(data);
        else
            spawn_skeleton(data);
}

static void display_hud(sfEvent event, data_t *data)
{
    if (event.key.code == sfKeyEscape)
        data->hud_state = 3;
    if (event.key.code == sfKeyE)
        data->hud_state = 4;
    if (event.key.code == sfKeyB)
        data->hud_state = 5;
    if (event.key.code == sfKeyN)
        data->hud_state = 6;
    if (sfKeyboard_isKeyPressed(sfKeyC)) {
        save_game(data, 1);
        notification(data, "  Game saved !", 0);
        notification(data, "  Game saved !", 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyV)) {
        load_game(data, 1);
        notification(data, "  Game loaded !", 0);
        notification(data, "  Game loaded !", 0);
    }
}

// debug function
static void meteo_changer(sfEvent event, data_t *data)
{
    if (event.key.code == sfKeyNumpad1)
        data->hud->meteo_status = 1;
    if (event.key.code == sfKeyNumpad2)
        data->hud->meteo_status = 2;
    if (event.key.code == sfKeyNumpad3)
        data->hud->meteo_status = 3;
    if (event.key.code == sfKeyP)
        give_quest(data, 0);
}

static void disable_hud(sfEvent event, data_t *data)
{
    if (event.key.code == sfKeyEscape && data->hud_state == 3)
        data->hud_state = 0;
    if (event.key.code == sfKeyE && data->hud_state == 4)
        data->hud_state = 0;
    if (event.key.code == sfKeyB && data->hud_state == 5)
        data->hud_state = 0;
    if (event.key.code == sfKeyN && data->hud_state == 6)
        data->hud_state = 0;
}

void event_handler(sfRenderWindow *window, sfEvent event, data_t *data)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (data->hud_state == 0)
            display_hud(event, data);
        else
            disable_hud(event, data);
        meteo_changer(event, data);
    }
    if (event.type == sfEvtKeyReleased) {
        if (UP(event) || DOWN(event) || LEFT(event) || RIGHT(event))
            data->player->animation = 0;
        if (SPACE(event))
            data->player->animation = 0;
    }
    item_hold_change(event, data);
    debug_life(data);
    action_menu(event, data);
}

// U can add debug_hitbox_collision(data);
// U can add sfRenderWindow_drawRectangleShape(data->window,
//    data->collision->hitbox, NULL);
void camera_handler(data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->player->player_sprite);

    pos.x += 48 / 2;
    pos.y += 48 / 2;
    sfSprite_setPosition(data->map->map_top, data->map->map_top_pos);
    display_drop_item(data);
    display_npc(data);
    if (data->tuto_mode)
        sfRenderWindow_drawSprite(data->window, data->tuto->tuto_top, NULL);
    else
        sfRenderWindow_drawSprite(data->window, data->map->map_top, NULL);
    //hud_player(data);
    meteo_display(data);
    if (data->player->doing_quest)
        display_mini_quest(data, data->player->quest_id);
    display_banner(data);
    sprint_check(data);
    sfView_setCenter(data->player->camera, pos);
    sfRenderWindow_setView(data->window, data->player->camera);
}

void draw_sprites(sfRenderWindow *window, data_t *data)
{
    if (data->tuto_mode == true) {
        sfRenderWindow_drawSprite(window, data->tuto->tuto, NULL);
    } else {
        sfRenderWindow_drawSprite(window, data->map->map_sprite, NULL);
    }
    if (data->player->animation == 0)
        idle(data, 0);
}

static void normal_game(data_t *data, sfEvent event)
{
    sfRenderWindow_clear(data->window, sfCyan);
    while (sfRenderWindow_pollEvent(data->window, &event))
        event_handler(data->window, event, data);
    dead_condition(data);
    background(data);
    player_movement(data);
    draw_sprites(data->window, data);
    check_monster(data);
    move_slime(data);
    move_skeleton(data);
    camera_handler(data);
    player_basics(event, data);
    recover_item(data);
    sfRenderWindow_display(data->window);
}

void game_loop(data_t *data)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;

    data->window = sfRenderWindow_create(mode, "My_RPG", sfClose, 0);
    sfRenderWindow_setFramerateLimit(data->window, 60);
    while (sfRenderWindow_isOpen(data->window)) {
        if (data->tuto_mode && !data->menu_mode)
            tutorial_game(data, event);
        if (data->menu_mode)
            menu(data);
        if (!data->menu_mode && !data->tuto_mode)
            normal_game(data, event);
    }
}

static void starter(data_t *data)
{
    data->menu_window = init_menu_window();
    data->map = init_map();
    data->player = init_player();
    data->menu = init_menu();
    data->pause = init_pause();
    data->hud = hud_init();
    data->inv = init_inventory();
    data->tuto = init_tuto();
    data->collision = init_collision();
    data->col_map = init_collision_map();
    data->ennemies = init_ennemies();
    init_music(data);
    init_items(data);
    init_life(data);
    init_notification_sprite(data);
    init_npc(data);
    init_text(data);
    init_bubble_text(data);
    start_meteo(data);
    init_mini_display(data);
}

int main(void)
{
    data_t *data = malloc(sizeof(data_t));

    data->tuto_mode = true;
    data->is_on_menu = true;
    data->menu_mode = true;
    data->sign_display = true;
    data->hud_state = 0;
    starter(data);
    init_quest(data);
    sfSprite_setPosition(data->player->player_sprite,
        (sfVector2f) {855, 1005});
    sfMusic_play(data->tutorial_music);
    game_loop(data);
    close_the_game(data);
    return 0;
}
