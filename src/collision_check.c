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
    npc_t *npc = data->npc;

    rectangle_up = get_rectangle_above_player(data);
    if (rectangle_up != NULL) {
        if (rectangle_up->collision != 0)
            return 1;
    }
    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, data->player->player_pos))
            return 1;
        npc = npc->next;
    }
    return 0;
}

int collision_check_down(data_t *data)
{
    collision_t *rectangle_down = NULL;
    npc_t *npc = data->npc;

    rectangle_down = get_rectangle_under_player(data);
    if (rectangle_down != NULL) {
        if (rectangle_down->collision != 0)
            return 1;
    }
    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, data->player->player_pos))
            return 1;
        npc = npc->next;
    }
    return 0;
}

int collision_check_left(data_t *data)
{
    collision_t *rectangle_left = NULL;
    npc_t *npc = data->npc;

    rectangle_left = get_rectangle_left_player(data);
    if (rectangle_left != NULL) {
        if (rectangle_left->collision != 0)
            return 1;
    }
    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, data->player->player_pos))
            return 1;
        npc = npc->next;
    }
    return 0;
}

int collision_check_right(data_t *data)
{
    collision_t *rectangle_right = NULL;
    npc_t *npc = data->npc;

    rectangle_right = get_rectangle_right_player(data);
    if (rectangle_right != NULL) {
        if (rectangle_right->collision != 0)
            return 1;
    }
    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, data->player->player_pos))
            return 1;
        npc = npc->next;
    }
    return 0;
}
