/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void attack_right(data_t *data)
{
    double seconds;

    data->player->elapsed_time = sfClock_getElapsedTime(data->player->clock);
    seconds = sfTime_asSeconds(data->player->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = 336;
        data->player->rect.left += 48;
        data->player->rect.height = 48;
        data->player->rect.width = 48;
        if (data->player->rect.left >= data->player->rect.width * 4) {
            data->player->rect.left = 0;
        }
        sfClock_restart(data->player->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
            data->player->rect);
    }
}

void attack_up(data_t *data)
{
    double seconds;

    data->player->elapsed_time = sfClock_getElapsedTime(data->player->clock);
    seconds = sfTime_asSeconds(data->player->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = 384;
        data->player->rect.left += 48;
        data->player->rect.height = 48;
        data->player->rect.width = 48;
        if (data->player->rect.left >= data->player->rect.width * 4) {
            data->player->rect.left = 0;
        }
        sfClock_restart(data->player->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
            data->player->rect);
    }
}

void attack_down(data_t *data)
{
    double seconds;

    data->player->elapsed_time = sfClock_getElapsedTime(data->player->clock);
    seconds = sfTime_asSeconds(data->player->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = 288;
        data->player->rect.left += 48;
        data->player->rect.height = 48;
        data->player->rect.width = 48;
        if (data->player->rect.left >= data->player->rect.width * 4) {
            data->player->rect.left = 0;
        }
        sfClock_restart(data->player->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
            data->player->rect);
    }
}

void attack_left(data_t *data)
{
    double seconds;

    data->player->elapsed_time = sfClock_getElapsedTime(data->player->clock);
    seconds = sfTime_asSeconds(data->player->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = 336;
        data->player->rect.left += 48;
        data->player->rect.height = 48;
        data->player->rect.width = 48;
        if (data->player->rect.left >= data->player->rect.width * 4) {
            data->player->rect.left = 0;
        }
        sfClock_restart(data->player->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
            data->player->rect);
    }
}

void attack(data_t *data)
{
    if (data->player->direction == 0)
        attack_up(data);
    if (data->player->direction == 1)
        attack_down(data);
    if (data->player->direction == 2)
        attack_left(data);
    if (data->player->direction == 3)
        attack_right(data);
}
