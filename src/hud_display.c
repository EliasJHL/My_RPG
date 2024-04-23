/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void pause_menu(data_t *data)
{
    sfVector2f view_center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {view_center.x - 416 / 2, view_center.y - 448 / 2};

    sfSprite_setPosition(data->pause->bg_pause, sprite_pos);
    sfRenderWindow_drawSprite(data->window, data->pause->bg_pause, NULL);
}

void inventory_menu(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - 1920 / 2, center.y - 1080 / 2};

    sfRectangleShape_setPosition(data->menu->shape, sprite_pos);
    sfRenderWindow_drawRectangleShape(data->window, data->menu->shape, NULL);
}
