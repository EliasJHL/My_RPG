/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void type_hud(data_t *data)
{
    if (data->hud_state == 3)
        pause_menu(data);
    if (data->hud_state == 4)
        inventory_menu(data);
}

void player_movement(sfEvent event, data_t *data)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyZ)
            sfSprite_move(data->player->player_sprite, (sfVector2f) {0, -5});
        if (event.key.code == sfKeyS)
            sfSprite_move(data->player->player_sprite, (sfVector2f) {0, 5});
        if (event.key.code == sfKeyQ)
            sfSprite_move(data->player->player_sprite, (sfVector2f) {-5, 0});
        if (event.key.code == sfKeyD)
            sfSprite_move(data->player->player_sprite, (sfVector2f) {5, 0});
    }
}

int player_basics(sfEvent event, data_t *data)
{
    type_hud(data);
    return 0;
}
