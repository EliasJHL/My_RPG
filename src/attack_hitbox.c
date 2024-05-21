/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void check_hit_slime(data_t *data, int i)
{
    sfFloatRect rect1 = GLOBAL(data->collision->hitbox);
    sfFloatRect rect2;
    sfFloatRect intersection;

    rect2 = GLOBAL(data->ennemies->slime[i]->hitbox);
    if (sfFloatRect_intersects(&rect1, &rect2, &intersection)) {
        data->ennemies->slime[i]->life -= 10;
        if (data->ennemies->slime[i]->life <= 0) {
            data->ennemies->slime[i]->is_alive = false;
        }
        if (data->player->direction == 0)
            data->ennemies->slime[i]->pos.y -= 10;
        if (data->player->direction == 1)
            data->ennemies->slime[i]->pos.y += 10;
        if (data->player->direction == 2)
            data->ennemies->slime[i]->pos.x -= 10;
        if (data->player->direction == 3)
            data->ennemies->slime[i]->pos.x += 10;
    }
}

void check_hit(data_t *data)
{
    for (int i = 0; i < 10; i++)
        check_hit_slime(data, i);
}

void hit_up_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f position = {player.x + 20, player.y + 20};

    sfRectangleShape_setPosition(data->collision->hitbox, position);
    check_hit(data);
}

void hit_right_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f position = {player.x + 33, player.y + 28};

    sfRectangleShape_setPosition(data->collision->hitbox, position);
    check_hit(data);
}

void hit_down_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f position = {player.x + 20, player.y + 43};

    sfRectangleShape_setPosition(data->collision->hitbox, position);
    check_hit(data);
}

void hit_left_player(data_t *data)
{
    sfVector2f player = data->player->player_pos;
    sfVector2f position = {player.x + 6, player.y + 28};

    sfRectangleShape_setPosition(data->collision->hitbox, position);
    check_hit(data);
}
