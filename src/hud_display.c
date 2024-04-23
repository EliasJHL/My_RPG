/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void pause_menu(data_t *data)
{
    sfRenderWindow_drawRectangleShape(data->window, data->menu->shape, NULL);
}

void inventory_menu(data_t *data)
{
    sfRenderWindow_drawRectangleShape(data->window, data->menu->shape, NULL);
}
