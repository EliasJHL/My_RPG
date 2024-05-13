/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

int collision_check_up(data_t *data)
{
    collision_t *rectangle_up = NULL;

    rectangle_up = get_rectangle_above_player(data);
    if (rectangle_up != NULL) {
        if (rectangle_up->collision != 0)
            return 1;
    }
    return 0;
}

int collision_check_down(data_t *data)
{
    collision_t *rectangle_down = NULL;

    rectangle_down = get_rectangle_under_player(data);
    if (rectangle_down != NULL) {
        if (rectangle_down->collision != 0)
            return 1;
    }
    return 0;
}

int collision_check_left(data_t *data)
{
    collision_t *rectangle_left = NULL;

    rectangle_left = get_rectangle_left_player(data);
    if (rectangle_left != NULL) {
        if (rectangle_left->collision != 0)
            return 1;
    }
    return 0;
}

int collision_check_right(data_t *data)
{
    collision_t *rectangle_right = NULL;

    rectangle_right = get_rectangle_right_player(data);
    if (rectangle_right != NULL) {
        if (rectangle_right->collision != 0)
            return 1;
    }
    return 0;
}
