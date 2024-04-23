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

static void release_position(sfEvent event, data_t *data)
{
    if (event.type == sfEvtKeyReleased) {
        if (event.key.code == sfKeyZ) {
            sfSprite_setTextureRect(data->player->player_sprite,
                (sfIntRect){0, 64, 64, 64});
        }
        if (event.key.code == sfKeyS) {
            sfSprite_setTextureRect(data->player->player_sprite,
                (sfIntRect){0, 0, 64, 64});
        }
        if (event.key.code == sfKeyQ) {
            sfSprite_setTextureRect(data->player->player_sprite,
                (sfIntRect){0, 192, 64, 64});
        }
        if (event.key.code == sfKeyD) {
            sfSprite_setTextureRect(data->player->player_sprite,
                (sfIntRect){0, 128, 64, 64});
        }
    }
}

void player_movement(sfEvent event, data_t *data)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyZ) {
            move_top(data);
            sfSprite_move(data->player->player_sprite, (sfVector2f) {0, -1});
        }
        if (event.key.code == sfKeyS) {
            move_down(data);
            sfSprite_move(data->player->player_sprite, (sfVector2f) {0, 1});
        }
        if (event.key.code == sfKeyQ) {
            move_left(data);
            sfSprite_move(data->player->player_sprite, (sfVector2f) {-1, 0});
        }
        if (event.key.code == sfKeyD) {
            move_right(data);
            sfSprite_move(data->player->player_sprite, (sfVector2f) {1, 0});
        }
    } else if (event.type == sfEvtKeyReleased) {
        release_position(event, data);
    }
}

int player_basics(sfEvent event, data_t *data)
{
    type_hud(data);
    return 0;
}
