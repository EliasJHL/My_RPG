/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void timer_damage(data_t *data)
{
    double seconds = 0;

    data->player->elapsed_time2 = sfClock_getElapsedTime(data->player->clock2);
    seconds = sfTime_asSeconds(data->player->elapsed_time2);
    if (seconds >= 1)
        data->player->damage_taken = false;
}