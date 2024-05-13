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
        notification(data, "New Achievement");
    if (sfKeyboard_isKeyPressed(sfKeyK))
        notification(data, "New Quest");
}

void debug_hitbox_collision(data_t *data)
{
    for (int i = 0; i < 14300; i++) {
        sfRenderWindow_drawRectangleShape(data->window,
            data->collision[i].col_sprite, NULL);
    }
}
