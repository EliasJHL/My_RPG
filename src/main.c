/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

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

void camera_handler(data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->player->player_sprite);

    pos.x += 48 / 2;
    pos.y += 48 / 2;
    sfView_setCenter(data->player->camera, pos);
    sfRenderWindow_setView(data->window, data->player->camera);
    sfRenderWindow_drawSprite(data->window, data->player->player_sprite, NULL);
    hud_player(data);
    meteo_display(data);
    debug_hitbox_collision(data);
}

void draw_sprites(sfRenderWindow *window, data_t *data)
{
    if (data->tuto_mode == true)
        sfRenderWindow_drawSprite(window, data->tuto->tuto, NULL);
    else
        sfRenderWindow_drawSprite(window, data->map->map_sprite, NULL);
    if (data->player->animation == 0)
        idle(data, 0);
}

static void normal_game(data_t *data, sfEvent event)
{
    while (sfRenderWindow_pollEvent(data->window, &event))
        event_handler(data->window, event, data);
    dead_condition(data);
    player_movement(data);
    sfRenderWindow_clear(data->window, sfCyan);
    background(data);
    draw_sprites(data->window, data);
    camera_handler(data);
    player_basics(event, data);
    sfRenderWindow_display(data->window);
}

void game_loop(data_t *data)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;

    data->window = sfRenderWindow_create(mode, "My_RPG", sfClose, 0);
    sfRenderWindow_setFramerateLimit(data->window, 60);
    while (sfRenderWindow_isOpen(data->window)) {
        if (data->tuto_mode == true) {
            tutorial_game(data, event);
        } else {
            normal_game(data, event);
        }
    }
}

static void starter(data_t *data)
{
    data->tuto_mode = true;
    data->hud_state = 0;
    data->map = init_map();
    data->player = init_player();
    data->menu = init_menu();
    data->pause = init_pause();
    data->hud = hud_init();
    data->inv = init_inventory();
    data->tuto = init_tuto();
    data->collision = init_collision();
    init_items(data);
    init_life(data);
    init_notification_sprite(data);
    start_meteo(data);
}

int main(void)
{
    data_t *data = malloc(sizeof(data_t));

    starter(data);
    if (data->tuto_mode == true)
        sfSprite_setPosition(data->player->player_sprite,
            (sfVector2f){855, 1005});
    game_loop(data);
    close_the_game(data);
    return 0;
}
