/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void inventory_menu_2(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f bg_pos = {center.x - 147, center.y - 123};

    sfRectangleShape_setPosition(data->inv->bg_player, bg_pos);
    sfRenderWindow_drawRectangleShape(data->window,
        data->inv->bg_player, NULL);
}
