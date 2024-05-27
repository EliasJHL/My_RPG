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
    data->player->life -= (life * (1 - (data->player->defense_stat / 100)));
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
    int level_stock = data->player->level;
    float growth_rate = 1.1;

    if (data->player->coef < 1)
        data->player->coef = 1;
    data->player->level = 0;
    data->player->xp += xp;
    xp_calc = data->player->xp;
    while (xp_calc > (200 * data->player->coef)){
        data->player->coef = pow(data->player->coef, growth_rate);
        xp_calc -= 200 * data->player->coef;
        data->player->level += 1;
    }
    if (data->player->level > level_stock)
        notification(data, "Level Up !", 0);
    data->player->xp_to_next = (200 * data->player->coef) - xp_calc;
}
