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
    int nb = 0;

    nb = data->tuto_mode ? 14300 : 87040;
    for (int i = 0; i < nb; i++) {
        col_pos = data->tuto_mode ? data->collision[i].col_pos :
            data->col_map[i].col_pos;
        if (col_pos.x >= player.x + 10 && col_pos.y >= player.y) {
            return data->tuto_mode ? &data->collision[i] : &data->col_map[i];
        }
    }
    return NULL;
}

collision_t *get_rectangle_under_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f col_pos;
    int nb = 0;

    nb = data->tuto_mode ? 14300 : 87040;
    for (int i = 0; i < nb; i++) {
        col_pos = data->tuto_mode ? data->collision[i].col_pos :
            data->col_map[i].col_pos;
        if (col_pos.x >= player.x + 10 && col_pos.y >= player.y + 10) {
            return data->tuto_mode ? &data->collision[i] : &data->col_map[i];
        }
    }
    return NULL;
}

collision_t *get_rectangle_left_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f col_pos;
    int nb = 0;

    nb = data->tuto_mode ? 14300 : 87040;
    for (int i = 0; i < nb; i++) {
        col_pos = data->tuto_mode ? data->collision[i].col_pos :
            data->col_map[i].col_pos;
        if (col_pos.x >= player.x && col_pos.y >= player.y + 10) {
            return data->tuto_mode ? &data->collision[i] : &data->col_map[i];
        }
    }
    return NULL;
}

collision_t *get_rectangle_right_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f col_pos;
    int nb = 0;

    nb = data->tuto_mode ? 14300 : 87040;
    for (int i = 0; i < nb; i++) {
        col_pos = data->tuto_mode ? data->collision[i].col_pos :
            data->col_map[i].col_pos;
        if (col_pos.x >= player.x + 20 && col_pos.y >= player.y + 10) {
            return data->tuto_mode ? &data->collision[i] : &data->col_map[i];
        }
    }
    return NULL;
}
