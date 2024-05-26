/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void move_right(data_t *data)
{
    sfVector2f old_position;

    if (RIGHT(event)) {
        old_position = data->player->player_pos;
        sfSprite_move(data->player->player_sprite,
            (sfVector2f){1.2 * data->sprint->speed, 0});
        data->player->player_pos = sfSprite_getPosition
            (data->player->player_sprite);
        if (collision_check_right(data)) {
            sfSprite_setPosition(data->player->player_sprite, old_position);
            data->player->player_pos = old_position;
            data->player->animation = 0;
        } else {
            data->player->direction = 3;
            move(data, 192);
        }
    }
}

void move_left(data_t *data)
{
    sfVector2f old_position;

    if (LEFT(event)) {
        old_position = data->player->player_pos;
        sfSprite_move(data->player->player_sprite,
            (sfVector2f){-1.2 * data->sprint->speed, 0});
        data->player->player_pos = sfSprite_getPosition
            (data->player->player_sprite);
        if (collision_check_left(data)) {
            sfSprite_setPosition(data->player->player_sprite, old_position);
            data->player->player_pos = old_position;
            data->player->animation = 0;
        } else {
            data->player->direction = 2;
            move(data, 528);
        }
    }
    move_right(data);
}

void move_down(data_t *data)
{
    sfVector2f old_position;

    if (!data->player->is_attacking)
        data->player->animation = 0;
    if (DOWN(event)) {
        old_position = data->player->player_pos;
        sfSprite_move(data->player->player_sprite,
            (sfVector2f){0, 1.2 * data->sprint->speed});
        data->player->player_pos = sfSprite_getPosition
            (data->player->player_sprite);
        if (collision_check_down(data)) {
            sfSprite_setPosition(data->player->player_sprite, old_position);
            data->player->player_pos = old_position;
            data->player->animation = 0;
        } else {
            data->player->direction = 1;
            move(data, 144);
        }
    }
    move_left(data);
}

void move_player(data_t *data)
{
    sfVector2f old_position;

    if (!UP(event) && !DOWN(event) && !LEFT(event) && !RIGHT(event))
            data->player->animation = 0;
    if (UP(event)) {
        old_position = data->player->player_pos;
        sfSprite_move(data->player->player_sprite,
            (sfVector2f){0, -1.2 * data->sprint->speed});
        data->player->player_pos = sfSprite_getPosition
            (data->player->player_sprite);
        if (collision_check_up(data)) {
            sfSprite_setPosition(data->player->player_sprite, old_position);
            data->player->player_pos = old_position;
            data->player->animation = 0;
        } else {
            data->player->direction = 0;
            move(data, 240);
        }
    }
    move_down(data);
}
