/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void hud_pause_actions(data_t *data, sfEvent event)
{
    if (is_clicked(data, data->pause->resume) == 1) {
        data->hud_state = 0;
    }
    if (is_clicked(data, data->pause->exit) == 1) {
        sfRenderWindow_close(data->window);
    }
}

void action_menu(sfEvent event, data_t *data)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (data->hud_state == 3)
            hud_pause_actions(data, event);
        if (data->hud_state == 4)
            inventory_menu(data);
    }
}
