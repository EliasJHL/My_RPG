/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void heal(int life, data_t *data)
{
    data->player->life += life;
    if (data->player->life > 200)
        data->player->life = 200;
    if (data->player->life < 0)
        data->player->life = 0;
}

void damage(int life, data_t *data)
{
    data->player->life -= life;
    if (data->player->life > 200)
        data->player->life = 200;
    if (data->player->life < 0)
        data->player->life = 0;
}

void eat(int food, data_t *data)
{
    data->player->hungry += food;
    if (data->player->hungry > 200)
        data->player->hungry = 200;
    if (data->player->hungry < 0)
        data->player->hungry = 0;
}

void starve(int food, data_t *data)
{
    data->player->hungry -= food;
    if (data->player->hungry > 200)
        data->player->hungry = 200;
    if (data->player->hungry < 0)
        data->player->hungry = 0;
}

void xp_add(int xp, data_t *data)
{
    int xp_calc = 0;

    data->player->level = 0;
    data->player->xp += xp;
    xp_calc = data->player->xp;
    while (xp_calc > 200) {
        xp_calc -= 200;
        data->player->level += 1;
    }
}
