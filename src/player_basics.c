/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void type_hud(data_t *data)
{
    if (data->hud_state == 3)
        pause_menu(data);
    if (data->hud_state == 4)
        inventory_menu(data);
}

void idle(data_t *data, int top)
{
    double seconds;

    data->player->elapsed_time = sfClock_getElapsedTime(data->player->clock);
    seconds = sfTime_asSeconds(data->player->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = top;
        data->player->rect.left += 48;
        data->player->rect.height = 48;
        data->player->rect.width = 48;
        if (data->player->rect.left >= data->player->rect.width * 6) {
            data->player->rect.left = 0;
        }
        sfClock_restart(data->player->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
                                data->player->rect);
    }
}

static void move_player(sfEvent event, data_t *data, sfVector2f *pos)
{
    if (UP(event)) {
        move(data, 240);
        pos->y -= 5;
    }
    if (DOWN(event)) {
        move(data, 144);
        pos->y += 5;
    }
    if (LEFT(event)) {
        move(data, 192);
        pos->x -= 5;
    }
    if (RIGHT(event)) {
        move(data, 192);
        pos->x += 5;
    }
}

void player_movement(sfEvent event, data_t *data, sfVector2f *pos)
{
    if (event.type == sfEvtKeyPressed) {
        data->player->animation = 1;
        move_player(event, data, pos);
    }
    if (event.type == sfEvtKeyReleased) {
        if (UP(event) || DOWN(event) || LEFT(event) || RIGHT(event))
            data->player->animation = 0;
    }
}

int player_basics(sfEvent event, data_t *data)
{
    type_hud(data);
    return 0;
}
