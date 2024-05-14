/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void reset_hit(data_t *data)
{
    sfColor reset = sfColor_fromRGBA(0, 0, 0, 0);

    for (int i = 0; i < 14300; i++) {
        sfRectangleShape_setFillColor(
            data->collision[i].col_sprite, reset);
    }
}

void hit_up_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfColor c = sfColor_fromRGB(255, 0, 0);
    sfVector2f hit;
    int u = 0;
    int u_l = 0;
    int u_r = 0;

    for (int i = 0; i < 14300; i++) {
        hit = data->collision[i].col_pos;
        if (hit.x >= player.x + 10 && hit.y >= player.y && u == 0) {
            sfRectangleShape_setFillColor(data->collision[i].col_sprite, c);
            u = 1;
        }
    }
}

void hit_right_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfColor c = sfColor_fromRGB(255, 0, 0);
    sfVector2f hit;
    int r = 0;
    int r_d = 0;

    for (int i = 0; i < 14300; i++) {
        hit = data->collision[i].col_pos;
        if (hit.x >= player.x + 20 && hit.y >= player.y + 20 && r == 0) {
            sfRectangleShape_setFillColor(data->collision[i].col_sprite, c);
            r = 1;
        }
        if (hit.x >= player.x + 10 && hit.y >= player.y + 30 && r_d == 0) {
            sfRectangleShape_setFillColor(data->collision[i].col_sprite, c);
            r_d = 1;
        }
    }
}
