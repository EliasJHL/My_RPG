/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

int is_hover(data_t *data, sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse_pos_pixel = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(data->window,
        mouse_pos_pixel, sfRenderWindow_getView(data->window));

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y))
        return 1;
    return 0;
}

int is_clicked_slot(data_t *data, sfRectangleShape *slot)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(slot);
    sfVector2i mouse_pos_pixel = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(data->window,
        mouse_pos_pixel, sfRenderWindow_getView(data->window));

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y))
        return 1;
    return 0;
}

int is_clicked(data_t *data, sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse_pos_pixel = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(data->window,
        mouse_pos_pixel, sfRenderWindow_getView(data->window));

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y))
        return 1;
    return 0;
}
