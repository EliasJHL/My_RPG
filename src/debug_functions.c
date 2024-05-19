/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void debug_life(data_t *data)
{
    if (sfKeyboard_isKeyPressed(sfKeyP))
        data->player->life += 10;
    if (sfKeyboard_isKeyPressed(sfKeyM))
        data->player->life -= 10;
    if (sfKeyboard_isKeyPressed(sfKeyL))
        notification(data, "New Achievement", 1);
    if (sfKeyboard_isKeyPressed(sfKeyK))
        notification(data, "New Quest", 0);
}

void debug_hitbox_collision(data_t *data)
{
    int nb = 0;

    nb = data->tuto_mode ? 14300 : 87039;
    for (int i = 0; i < nb; i++) {
        if (data->tuto_mode)
            sfRenderWindow_drawRectangleShape(data->window,
                data->collision[i].col_sprite, NULL);
        else
            sfRenderWindow_drawRectangleShape(data->window,
                data->col_map[i].col_sprite, NULL);
    }
}
