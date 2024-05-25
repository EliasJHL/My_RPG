/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static int check_collision_2(data_t *data, skeleton_t *skeleton)
{
    if (skeleton->dir == 3) {
        if (collision_check_down_skeleton(data, skeleton) != 0)
            return 1;
        else
            return 0;
    }
    if (skeleton->dir == 4) {
        if (collision_check_up_skeleton(data, skeleton) != 0)
            return 1;
        else
            return 0;
    }
    return 0;
}

static int check_collision(data_t *data, skeleton_t *skeleton)
{
    if (skeleton->dir == 1) {
        if (collision_check_right_skeleton(data, skeleton) != 0)
            return 1;
        else
            return 0;
    }
    if (skeleton->dir == 2) {
        if (collision_check_left_skeleton(data, skeleton) != 0)
            return 1;
        else
            return 0;
    }
    return check_collision_2(data, skeleton);
}

static void auto_true(data_t *data, skeleton_t *skeleton)
{
    if (skeleton->auto_mode_moov == true) {
        if (check_collision(data, skeleton) == 1)
            skeleton->dir = (rand() % 4) + 1;
        skeleton->is_mooving = true;
        if (skeleton->dir == 1)
            skeleton->pos.x += 0.3;
        if (skeleton->dir == 2)
            skeleton->pos.x -= 0.3;
        if (skeleton->dir == 3)
            skeleton->pos.y += 0.3;
        if (skeleton->dir == 4)
            skeleton->pos.y -= 0.3;
        skeleton->elapsed_times2 = sfClock_getElapsedTime(
            skeleton->clock2);
        if (sfTime_asSeconds(skeleton->elapsed_times2) >
            skeleton->auto_time) {
            skeleton->auto_mode_moov = false;
            sfClock_restart(skeleton->clock2);
        }
    }
}

void auto_mode_skeleton(data_t *data, skeleton_t *skeleton)
{
    if (skeleton->auto_mode == false) {
        skeleton->auto_mode = true;
        skeleton->auto_mode_moov = false;
        skeleton->auto_time = (rand() % 7) + 1;
        sfClock_restart(skeleton->clock2);
    }
    auto_true(data, skeleton);
    if (skeleton->auto_mode_moov == false) {
        skeleton->is_mooving = false;
        skeleton->elapsed_times2 = sfClock_getElapsedTime(
            skeleton->clock2);
        if (sfTime_asSeconds(skeleton->elapsed_times2) >
            skeleton->auto_time) {
            skeleton->auto_time = (rand() % 4) + 1;
            skeleton->auto_mode_moov = true;
            sfClock_restart(skeleton->clock2);
            skeleton->dir = (rand() % 4) + 1;
        }
    }
}

static void move_skeleton_left(data_t *data, sfVector2f pos,
    skeleton_t *skeleton, float distance)
{
    if (skeleton->pos.x < pos.x - 20) {
        skeleton->pos.x += 0.3;
    } else if (skeleton->pos.x > pos.x - 20)
        skeleton->pos.x -= 0.3;
}

static void move_skeleton_right(data_t *data, sfVector2f pos,
    skeleton_t *skeleton, float distance)
{
    if (skeleton->pos.x > pos.x + 20) {
        skeleton->pos.x -= 0.3;
    } else if (skeleton->pos.x < pos.x + 20)
        skeleton->pos.x += 0.3;
}

static void move_skeleton_true(data_t *data, sfVector2f pos,
    skeleton_t *skeleton, float distance)
{
    if (distance < 200) {
        if (skeleton->pos.x < pos.x)
            move_skeleton_left(data, pos, skeleton, distance);
        if (skeleton->pos.x > pos.x)
            move_skeleton_right(data, pos, skeleton, distance);
        if (skeleton->pos.y < pos.y)
            skeleton->pos.y += 0.3;
        if (skeleton->pos.y > pos.y)
            skeleton->pos.y -= 0.3;
    }
    if (distance >= 200)
        auto_mode_skeleton(data, skeleton);
    else
        skeleton->auto_mode = false;
}

void move_skeleton(data_t *data)
{
    float distance;
    sfVector2f pos = data->player->player_pos;
    sfVector2f pos2;

    pos.x -= 7;
    pos.y -= 13;
    for (int i = 0; i < 10; i++) {
        if (data->ennemies->skeleton[i]->is_alive == true &&
            !data->ennemies->skeleton[i]->is_attacking) {
            distance = sqrt(pow(data->ennemies->skeleton[i]->pos.x - pos.x, 2)
            + pow(data->ennemies->skeleton[i]->pos.y - pos.y, 2));
            move_skeleton_true(data, pos,
                data->ennemies->skeleton[i], distance);
            pos2 = data->ennemies->skeleton[i]->pos;
            pos2.x += 45;
            pos2.y += 40;
            sfRectangleShape_setPosition(data->ennemies->skeleton[i]->
                attack_hitbox, pos2);
        }
    }
}
