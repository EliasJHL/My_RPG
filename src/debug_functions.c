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
        notification(data, 1);
}
