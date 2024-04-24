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
    sfVector2f pos = sfSprite_getPosition(data->player->player_sprite);

    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyZ) {
            move(data, 320);
            pos.y -= 1;
        }
        if (event.key.code == sfKeyS) {
            move(data, 256);
            pos.y += 1;
        }
        if (event.key.code == sfKeyQ) {
            move(data, 448);
            pos.x -= 1;
        }
        if (event.key.code == sfKeyD) {
            move(data, 384);
            pos.x += 1;
        }
        sfSprite_setPosition(data->player->player_sprite, pos);
    } else if (event.type == sfEvtKeyReleased) {
        release_position(event, data);
    }
}

int player_basics(sfEvent event, data_t *data)
{
    type_hud(data);
    return 0;
}
