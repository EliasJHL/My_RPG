/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static collision_t *get_rectangle_above_skeleton(data_t *data,
    skeleton_t *skeleton)
{
    sfVector2f pos = skeleton->pos;
    sfVector2f col_pos;
    int nb = 0;

    nb = data->tuto_mode ? 14300 : 87040;
    for (int i = 0; i < nb; i++) {
        col_pos = data->tuto_mode ? data->collision[i].col_pos :
            data->col_map[i].col_pos;
        if (col_pos.x >= pos.x + 10 && col_pos.y >= pos.y) {
            return data->tuto_mode ? &data->collision[i] : &data->col_map[i];
        }
    }
    return NULL;
}

static collision_t *get_rectangle_under_skeleton(data_t *data,
    skeleton_t *skeleton)
{
    sfVector2f pos = skeleton->pos;
    sfVector2f col_pos;
    int nb = 0;

    nb = data->tuto_mode ? 14300 : 87040;
    for (int i = 0; i < nb; i++) {
        col_pos = data->tuto_mode ? data->collision[i].col_pos :
            data->col_map[i].col_pos;
        if (col_pos.x >= pos.x + 10 && col_pos.y >= pos.y + 10) {
            return data->tuto_mode ? &data->collision[i] : &data->col_map[i];
        }
    }
    return NULL;
}

static collision_t *get_rectangle_left_skeleton(data_t *data,
    skeleton_t *skeleton)
{
    sfVector2f pos = skeleton->pos;
    sfVector2f col_pos;
    int nb = 0;

    nb = data->tuto_mode ? 14300 : 87040;
    for (int i = 0; i < nb; i++) {
        col_pos = data->tuto_mode ? data->collision[i].col_pos :
            data->col_map[i].col_pos;
        if (col_pos.x >= pos.x && col_pos.y >= pos.y + 10) {
            return data->tuto_mode ? &data->collision[i] : &data->col_map[i];
        }
    }
    return NULL;
}

static collision_t *get_rectangle_right_skeleton(data_t *data,
    skeleton_t *skeleton)
{
    sfVector2f pos = skeleton->pos;
    sfVector2f col_pos;
    int nb = 0;

    nb = data->tuto_mode ? 14300 : 87040;
    for (int i = 0; i < nb; i++) {
        col_pos = data->tuto_mode ? data->collision[i].col_pos :
            data->col_map[i].col_pos;
        if (col_pos.x >= pos.x + 20 && col_pos.y >= pos.y + 10) {
            return data->tuto_mode ? &data->collision[i] : &data->col_map[i];
        }
    }
    return NULL;
}

int collision_check_up_skeleton(data_t *data, skeleton_t *skeleton)
{
    collision_t *rectangle_up = NULL;
    npc_t *npc = data->npc;

    rectangle_up = get_rectangle_above_skeleton(data, skeleton);
    if (rectangle_up != NULL) {
        if (rectangle_up->collision != 0)
            return 1;
    }
    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, skeleton->pos, 10) &&
            data->tuto_mode == npc->is_tuto)
            return 1;
        npc = npc->next;
    }
    return 0;
}

int collision_check_down_skeleton(data_t *data, skeleton_t *skeleton)
{
    collision_t *rectangle_down = NULL;
    npc_t *npc = data->npc;

    rectangle_down = get_rectangle_under_skeleton(data, skeleton);
    if (rectangle_down != NULL) {
        if (rectangle_down->collision != 0)
            return 1;
    }
    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, skeleton->pos, 10) &&
            data->tuto_mode == npc->is_tuto)
            return 1;
        npc = npc->next;
    }
    return 0;
}

int collision_check_left_skeleton(data_t *data, skeleton_t *skeleton)
{
    collision_t *rectangle_left = NULL;
    npc_t *npc = data->npc;

    rectangle_left = get_rectangle_left_skeleton(data, skeleton);
    if (rectangle_left != NULL) {
        if (rectangle_left->collision != 0)
            return 1;
    }
    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, skeleton->pos, 10) &&
            data->tuto_mode == npc->is_tuto)
            return 1;
        npc = npc->next;
    }
    return 0;
}

int collision_check_right_skeleton(data_t *data, skeleton_t *skeleton)
{
    collision_t *rectangle_right = NULL;
    npc_t *npc = data->npc;

    rectangle_right = get_rectangle_right_skeleton(data, skeleton);
    if (rectangle_right != NULL) {
        if (rectangle_right->collision != 0)
            return 1;
    }
    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, skeleton->pos, 10) &&
            data->tuto_mode == npc->is_tuto)
            return 1;
        npc = npc->next;
    }
    return 0;
}
