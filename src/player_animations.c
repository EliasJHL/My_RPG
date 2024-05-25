/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void move(data_t *data, int top)
{
    double seconds;
    double cond = 0;

    data->player->elapsed_time = sfClock_getElapsedTime(data->player->clock);
    seconds = sfTime_asSeconds(data->player->elapsed_time);
    cond = data->sprint->speed == 1 ? 0 : 0.05;
    if (seconds >= (0.15 - cond)) {
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
