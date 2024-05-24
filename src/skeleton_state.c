/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void choose_state_mooving(skeleton_t *skeleton, float distance)
{
    if (distance < 200) {
        if (!skeleton->is_mooving) {
            sfClock_restart(skeleton->clock);
            skeleton->rect.left = 0;
        }
        skeleton->is_mooving = true;
        skeleton->auto_mode = false;
    } else
        skeleton->is_mooving = false;
}

static void choose_state_attack(skeleton_t *skeleton, sfFloatRect rect1,
    sfFloatRect rect2, sfFloatRect intersection)
{
    if (sfFloatRect_intersects(&rect1, &rect2, &intersection)) {
        if (!skeleton->is_attacking) {
            sfClock_restart(skeleton->clock);
            skeleton->rect.left = 0;
        }
        skeleton->is_attacking = true;
        skeleton->auto_mode = false;
    } else
        skeleton->is_attacking = false;
}

void choose_state(data_t *data, int i)
{
    float distance;
    sfFloatRect rect1 = GLOBAL(data->player->hitbox);
    sfFloatRect rect2;
    sfFloatRect intersection;
    sfVector2f pos = data->player->player_pos;

    pos.x += 9;
    pos.y += 19;
    if (data->ennemies->slime[i]->is_alive == true) {
        distance = sqrt(pow(SKELETON_X - PLAYER_X, 2) +
                        pow(SKELETON_Y - PLAYER_Y, 2));
        choose_state_mooving(data->ennemies->skeleton[i], distance);
        rect2 = GLOBAL(data->ennemies->skeleton[i]->attack_hitbox);
        choose_state_attack(data->ennemies->skeleton[i], rect1, rect2,
            intersection);
    }
}
