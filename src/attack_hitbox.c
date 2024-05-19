/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void hit_up_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f position = {player.x + 20, player.y + 20};

    sfRectangleShape_setPosition(data->collision->hitbox, position);
}

void hit_right_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f position = {player.x + 33, player.y + 28};

    sfRectangleShape_setPosition(data->collision->hitbox, position);
}

void hit_down_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f position = {player.x + 20, player.y + 43};

    sfRectangleShape_setPosition(data->collision->hitbox, position);
}

void hit_left_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f position = {player.x + 6, player.y + 28};
    
    sfRectangleShape_setPosition(data->collision->hitbox, position);
}
