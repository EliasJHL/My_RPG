/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

collision_t *get_rectangle_above_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f col_pos;

    for (int i = 0; i < 14300; i++) {
        col_pos = data->collision[i].col_pos;
        if (col_pos.x >= player.x + 10 && col_pos.y >= player.y) {
            return &data->collision[i];
        }
    }
    return NULL;
}

collision_t *get_rectangle_under_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f col_pos;

    for (int i = 0; i < 14300; i++) {
        col_pos = data->collision[i].col_pos;
        if (col_pos.x >= player.x + 10 && col_pos.y >= player.y + 10) {
            return &data->collision[i];
        }
    }
    return NULL;
}

collision_t *get_rectangle_left_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f col_pos;

    for (int i = 0; i < 14300; i++) {
        col_pos = data->collision[i].col_pos;
        if (col_pos.x >= player.x && col_pos.y >= player.y + 10) {
            return &data->collision[i];
        }
    }
    return NULL;
}

collision_t *get_rectangle_right_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f col_pos;

    for (int i = 0; i < 14300; i++) {
        col_pos = data->collision[i].col_pos;
        if (col_pos.x >= player.x + 20 && col_pos.y >= player.y + 10) {
            return &data->collision[i];
        }
    }
    return NULL;
}
