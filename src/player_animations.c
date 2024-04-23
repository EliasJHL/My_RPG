/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void move_top(data_t *data)
{
    double seconds;

    data->elapsed_time = sfClock_getElapsedTime(data->clock);
    seconds = sfTime_asSeconds(data->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = 320;
        data->player->rect.left += 64;
        data->player->rect.height = 64;
        data->player->rect.width = 64;
        if (data->player->rect.left >= data->player->rect.width * 6) {
            data->player->rect.left = 0;
        }
        sfClock_restart(data->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
            data->player->rect);
    }
}

void move_right(data_t *data)
{
    double seconds;

    data->elapsed_time = sfClock_getElapsedTime(data->clock);
    seconds = sfTime_asSeconds(data->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = 384;
        data->player->rect.left += 64;
        data->player->rect.height = 64;
        data->player->rect.width = 64;
        if (data->player->rect.left >= data->player->rect.width * 6) {
            data->player->rect.left = 0;
        }
        sfClock_restart(data->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
            data->player->rect);
    }
}

void move_left(data_t *data)
{
    double seconds;

    data->elapsed_time = sfClock_getElapsedTime(data->clock);
    seconds = sfTime_asSeconds(data->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = 448;
        data->player->rect.left += 64;
        data->player->rect.height = 64;
        data->player->rect.width = 64;
        if (data->player->rect.left >= data->player->rect.width * 6) {
            data->player->rect.left = 0;
        }
        sfClock_restart(data->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
            data->player->rect);
    }
}

void move_down(data_t *data)
{
    double seconds;

    data->elapsed_time = sfClock_getElapsedTime(data->clock);
    seconds = sfTime_asSeconds(data->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = 256;
        data->player->rect.left += 64;
        data->player->rect.height = 64;
        data->player->rect.width = 64;
        if (data->player->rect.left >= data->player->rect.width * 6) {
            data->player->rect.left = 0;
        }
        sfClock_restart(data->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
            data->player->rect);
    }
}
