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

void hud_pause_actions(data_t *data, sfEvent event)
{
    if (is_clicked(data, data->pause->resume) == 1)
        data->hud_state = 0;
    if (is_clicked(data, data->pause->exit) == 1)
        sfRenderWindow_close(data->window);
}

void hud_pause_hover(data_t *data)
{
    sfColor hover = sfColor_fromRGB(235, 235, 235);

    sfSprite_setColor(data->pause->resume, sfWhite);
    sfSprite_setColor(data->pause->exit, sfWhite);
    sfSprite_setColor(data->pause->menu, sfWhite);
    sfSprite_setColor(data->pause->options, sfWhite);
    if (is_hover(data, data->pause->resume) == 1)
        sfSprite_setColor(data->pause->resume, hover);
    if (is_hover(data, data->pause->exit) == 1)
        sfSprite_setColor(data->pause->exit, hover);
    if (is_hover(data, data->pause->menu) == 1)
        sfSprite_setColor(data->pause->menu, hover);
    if (is_hover(data, data->pause->options) == 1)
        sfSprite_setColor(data->pause->options, hover);
}

void action_menu(sfEvent event, data_t *data)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (data->hud_state == 3)
            hud_pause_actions(data, event);
        if (data->hud_state == 4)
            inventory_menu(data);
    }
    if (event.type == sfEvtMouseMoved) {
        if (data->hud_state == 3) {
            hud_pause_hover(data);
        }
    }
}
