/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static int calc_change(int left)
{
    if (left == 64 * 0)
        return 64 * 6;
    if (left == 64 * 1)
        return 64 * 5;
    if (left == 64 * 2)
        return 64 * 4;
    if (left == 64 * 3)
        return 64 * 3;
    if (left == 64 * 4)
        return 64 * 2;
    if (left == 64 * 5)
        return 64 * 1;
    if (left == 64 * 6)
        return 64 * 0;
}

static void skeleton_moove_left(data_t *data, int i)
{
    static bool old = false;

    if (old != false && data->ennemies->skeleton[i]->side == false) {
        data->ennemies->skeleton[i]->rect.left = calc_change(
            data->ennemies->skeleton[i]->rect.left);
        old = false;
    }
    if (old != true && data->ennemies->skeleton[i]->side == true) {
        data->ennemies->skeleton[i]->rect.left = calc_change(
            data->ennemies->skeleton[i]->rect.left);
        old = true;
    }
    if (data->ennemies->skeleton[i]->side == false &&
        data->ennemies->skeleton[i]->rect.left >= 64 * 6)
        data->ennemies->skeleton[i]->rect.left = 0;
    if (data->ennemies->skeleton[i]->side == true &&
        data->ennemies->skeleton[i]->rect.left <= 0)
        data->ennemies->skeleton[i]->rect.left = 64 * 5;
}

static void skeleton_moove_up(data_t *data, int i)
{
    if (data->ennemies->skeleton[i]->side == false) {
        data->ennemies->skeleton[i]->rect.top = 64;
        data->ennemies->skeleton[i]->rect.left += 64;
    } else {
        data->ennemies->skeleton[i]->rect.top = 384;
        data->ennemies->skeleton[i]->rect.left -= 64;
    }
}

void skeleton_moove(data_t *data, int i)
{
    double seconds;
    static bool old = false;

    skeleton_moove_left(data, i);
    data->ennemies->skeleton[i]->elapsed_times = sfClock_getElapsedTime(
        data->ennemies->skeleton[i]->clock);
    seconds = sfTime_asSeconds(data->ennemies->skeleton[i]->elapsed_times);
    if (seconds > 0.30) {
        skeleton_moove_up(data, i);
        data->ennemies->skeleton[i]->rect.height = 64;
        data->ennemies->skeleton[i]->rect.width = 64;
        skeleton_moove_left(data, i);
        sfClock_restart(data->ennemies->skeleton[i]->clock);
        sfSprite_setTextureRect(data->ennemies->skeleton[i]->sprite,
            data->ennemies->skeleton[i]->rect);
    }
}
