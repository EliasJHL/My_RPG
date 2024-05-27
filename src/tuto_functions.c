/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void check_monster(data_t *data)
{
    for (int i = 0; i < 10; i++)
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

void display_header(data_t *data, int i)
{
    static float angle = 0;
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - (608 / 2) * 0.8,
        center.y - (176 / 2) * 0.8 - 300};
    sfVector2f effect_pos;
    sfVector2u sprite_size = (sfVector2u){1628, 1628};

    if (i <= 100)
        sprite_pos.y += i;
    if (i > 100)
        sprite_pos.y += 100;
    angle += 0.5;
    effect_pos = (sfVector2f){sprite_pos.x + 240, sprite_pos.y + 30};
    sfSprite_setOrigin(data->tuto->finsish_effect,
        (sfVector2f){sprite_size.x / 2, sprite_size.y / 2});
    sfSprite_setRotation(data->tuto->finsish_effect, angle);
    sfSprite_setPosition(data->tuto->finsish_effect, effect_pos);
    sfSprite_setPosition(data->tuto->tuto_finsished, sprite_pos);
    sfRenderWindow_drawSprite(data->window, data->tuto->finsish_effect, NULL);
    sfRenderWindow_drawSprite(data->window, data->tuto->tuto_finsished, NULL);
}

static void tuto_progress(data_t *data)
{
    if (UP(event) || DOWN(event) || LEFT(event) || RIGHT(event))
        data->tuto->move = true;
    if (data->tuto->move == true && sfKeyboard_isKeyPressed(sfKeyE)
        && data->hud_state == 0)
        data->tuto->inventory = true;
    if (data->tuto->inventory == true && data->tuto->move == true &&
            sfKeyboard_isKeyPressed(sfKeySpace) && data->hud_state == 0)
        data->tuto->attack = true;
}

static void tuto_finished(data_t *data)
{
    sfTime time;
    float seconds;
    static int i = 0;

    if (data->tuto->attack == true) {
        notification(data, "New Achievement !", 1);
        time = sfClock_getElapsedTime(data->tuto->clock);
        seconds = sfTime_asSeconds(time);
        display_header(data, i);
        i += 3;
        if (seconds > 5) {
            data->player->player_pos = data->player->spawn_point;
            sfClock_destroy(data->tuto->clock);
            data->tuto_mode = false;
        }
    } else {
        sfClock_restart(data->tuto->clock);
        i = 0;
    }
}

void tutorial_game(data_t *data, sfEvent event)
{
    while (sfRenderWindow_pollEvent(data->window, &event))
        event_handler(data->window, event, data);
    player_movement(data);
    sfRenderWindow_clear(data->window, sfColor_fromRGB(80, 140, 180));
    draw_sprites(data->window, data);
    check_monster(data);
    move_slime(data);
    move_skeleton(data);
    camera_handler(data);
    player_basics(event, data);
    tuto_progress(data);
    tuto_finished(data);
    sfRenderWindow_display(data->window);
}
