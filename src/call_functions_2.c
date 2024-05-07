/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

int dead_condition(data_t *data)
{
    sfVector2f pos = data->player->player_pos;

    if (data->player->life == 0) {
        pos = data->player->spawn_point;
        data->player->life = 200;
    }
    sfSprite_setPosition(data->player->player_sprite, pos);
    return 0;
}
