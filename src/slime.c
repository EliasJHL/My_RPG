/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void display_slime(data_t *data)
{
    sfVector2f pos = {0, 0};

    for (int i = 0; i < 10; i++) {
        if (data->ennemies->slime[i]->is_alive == true) {
            sfSprite_setPosition(data->ennemies->slime[i]->sprite,
                data->ennemies->slime[i]->pos);
            sfRenderWindow_drawSprite(data->window,
                data->ennemies->slime[i]->sprite, NULL);
            pos = data->ennemies->slime[i]->pos;
            pos.y += 10;
            pos.x += 9;
            sfRectangleShape_setPosition(data->ennemies->slime[i]->hitbox,
                pos);
            sfRenderWindow_drawRectangleShape(data->window, data->ennemies->slime[i]->hitbox,
                NULL);
        }
    }
}

void move_slime(data_t *data)
{
    float distance;
    int dir = (rand() % 4) + 1;
    sfVector2f pos = data->player->player_pos;
    pos.x += 9;
    pos.y += 19;
    for (int i = 0; i < 10; i++) {
        if (data->ennemies->slime[i]->is_alive == true) {
            distance = sqrt(pow(data->ennemies->slime[i]->pos.x - data->player->player_pos.x, 2) +
                            pow(data->ennemies->slime[i]->pos.y - data->player->player_pos.y, 2));
            if (distance < 150) {
                if (data->ennemies->slime[i]->pos.x < pos.x)
                    data->ennemies->slime[i]->pos.x += 0.3;
                if (data->ennemies->slime[i]->pos.x > pos.x)
                    data->ennemies->slime[i]->pos.x -= 0.3;
                if (data->ennemies->slime[i]->pos.y < pos.y)
                    data->ennemies->slime[i]->pos.y += 0.3;
                if (data->ennemies->slime[i]->pos.y > pos.y)
                    data->ennemies->slime[i]->pos.y -= 0.3;
            }
        } else {
            printf("dir = %d\n", dir);
            if (dir == 1)
                data->ennemies->slime[i]->pos.x += 0.3;
            if (dir == 2)
                data->ennemies->slime[i]->pos.x -= 0.3;
            if (dir == 3)
                data->ennemies->slime[i]->pos.y += 0.3;
            if (dir == 4)
                data->ennemies->slime[i]->pos.y -= 0.3;
        }
    }
}

void spawn_slime(data_t *data, sfVector2f pos)
{
    int i = 0;
    while (data->ennemies->slime[i]->is_alive == false) {
        data->ennemies->slime[i]->is_alive = true;
        data->ennemies->slime[i]->pos = pos;
        data->ennemies->slime[i]->life = 100;
    }
}