/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void init_skeleton(ennemies_t *ennemies)
{
    sfTexture *txt = sfTexture_createFromFile(TEXT_SKELETON, NULL);

    for (int i = 0; i < 10; i++) {
        SKELETON = malloc(sizeof(skeleton_t));
        SKELETON->life = 100;
        SKELETON->clock = sfClock_create();
        SKELETON->sprite = sfSprite_create();
        sfSprite_setTexture(SKELETON->sprite, txt, sfTrue);
        sfSprite_setTextureRect(SKELETON->sprite, (sfIntRect){0, 0, 64, 64});
        sfSprite_setScale(SKELETON->sprite, (sfVector2f){1, 1});
        SKELETON->is_alive = false;
        SKELETON->is_mooving = false;
        SKELETON->is_attacking = false;
        SKELETON->hitbox = sfRectangleShape_create();
        sfRectangleShape_setSize(SKELETON->hitbox, (sfVector2f){14, 14});
        sfRectangleShape_setFillColor(SKELETON->hitbox, sfTransparent);
        sfRectangleShape_setOutlineThickness(SKELETON->hitbox, 1);
        sfRectangleShape_setOutlineColor(SKELETON->hitbox, sfRed);
    }
    free(txt);
}

static void skeleton_attack(data_t *data, int i)
{
    double seconds;

    data->ennemies->skeleton[i]->elapsed_times = sfClock_getElapsedTime(
        data->ennemies->skeleton[i]->clock);
    seconds = sfTime_asSeconds(data->ennemies->skeleton[i]->elapsed_times);
    if (seconds > 0.15) {
        data->ennemies->skeleton[i]->rect.top = 128;
        data->ennemies->skeleton[i]->rect.left += 64;
        data->ennemies->skeleton[i]->rect.height = 64;
        data->ennemies->skeleton[i]->rect.width = 64;
        if (data->ennemies->skeleton[i]->rect.left >= 64 * 5)
            data->ennemies->skeleton[i]->rect.left = 0;
        sfClock_restart(data->ennemies->skeleton[i]->clock);
        sfSprite_setTextureRect(data->ennemies->skeleton[i]->sprite,
            data->ennemies->skeleton[i]->rect);
    }
}

static void skeleton_moove(data_t *data, int i)
{
    double seconds;

    data->ennemies->skeleton[i]->elapsed_times = sfClock_getElapsedTime(
        data->ennemies->skeleton[i]->clock);
    seconds = sfTime_asSeconds(data->ennemies->skeleton[i]->elapsed_times);
    if (seconds > 0.30) {
        data->ennemies->skeleton[i]->rect.top = 64;
        data->ennemies->skeleton[i]->rect.left += 64;
        data->ennemies->skeleton[i]->rect.height = 64;
        data->ennemies->skeleton[i]->rect.width = 64;
        if (data->ennemies->skeleton[i]->rect.left >= 64 * 6)
            data->ennemies->skeleton[i]->rect.left = 0;
        sfClock_restart(data->ennemies->skeleton[i]->clock);
        sfSprite_setTextureRect(data->ennemies->skeleton[i]->sprite,
            data->ennemies->skeleton[i]->rect);
    }
}

static void skeleton_idle(data_t *data, int i)
{
    double seconds;

    data->ennemies->skeleton[i]->elapsed_times = sfClock_getElapsedTime(
        data->ennemies->skeleton[i]->clock);
    seconds = sfTime_asSeconds(data->ennemies->skeleton[i]->elapsed_times);
    if (seconds > 0.30) {
        data->ennemies->skeleton[i]->rect.top = 0;
        data->ennemies->skeleton[i]->rect.left += 64;
        data->ennemies->skeleton[i]->rect.height = 64;
        data->ennemies->skeleton[i]->rect.width = 64;
        if (data->ennemies->skeleton[i]->rect.left >= 64 * 6)
            data->ennemies->skeleton[i]->rect.left = 0;
        sfClock_restart(data->ennemies->skeleton[i]->clock);
        sfSprite_setTextureRect(data->ennemies->skeleton[i]->sprite,
            data->ennemies->skeleton[i]->rect);
    }
}

static void choose_state(data_t *data, int i)
{
    float distance;
    sfVector2f pos = data->player->player_pos;

    pos.x += 9;
    pos.y += 19;
    if (data->ennemies->slime[i]->is_alive == true) {
        distance = sqrt(pow(SKELETON_X - PLAYER_X, 2) +
                        pow(SKELETON_Y - PLAYER_Y, 2));
        if (distance < 200)
            data->ennemies->skeleton[i]->is_mooving = true;
        else
            data->ennemies->skeleton[i]->is_mooving = false;
        if (distance < 50)
            data->ennemies->skeleton[i]->is_attacking = true;
        else
            data->ennemies->skeleton[i]->is_attacking = false;
    }
}

static void choose_anim(data_t *data)
{
    for (int i = 0; i < 10; i++) {
        choose_state(data, i);
        if (!data->ennemies->skeleton[i]->is_mooving &&
            !data->ennemies->skeleton[i]->is_attacking)
            skeleton_idle(data, i);
        if (data->ennemies->skeleton[i]->is_mooving &&
            !data->ennemies->skeleton[i]->is_attacking)
            skeleton_moove(data, i);
        if (data->ennemies->skeleton[i]->is_attacking)
            skeleton_attack(data, i);
    }
}

void display_skeleton(data_t *data)
{
    sfVector2f pos = {0, 0};

    choose_anim(data);
    for (int i = 0; i < 10; i++) {
        if (data->ennemies->skeleton[i]->is_alive == true) {
            sfSprite_setPosition(data->ennemies->skeleton[i]->sprite,
                data->ennemies->skeleton[i]->pos);
            sfRenderWindow_drawSprite(data->window,
                data->ennemies->skeleton[i]->sprite, NULL);
            pos = data->ennemies->skeleton[i]->pos;
            pos.y += 41;
            pos.x += 25;
            sfRectangleShape_setPosition(data->ennemies->skeleton[i]->hitbox,
                pos);
        }
    }
}

void spawn_skeleton(data_t *data)
{
    sfVector2f pos = {0, 0};

    for (int i = 0; i < 10; i++) {
        if (data->ennemies->skeleton[i]->is_alive == true)
            continue;
        pos.x = (rand() % (data->ennemies->skeletonx2 -
            data->ennemies->skeletonx1 + 1)) + data->ennemies->skeletonx1;
        pos.y = (rand() % (data->ennemies->skeletony2 -
            data->ennemies->skeletony1 + 1)) + data->ennemies->skeletony1;
        data->ennemies->skeleton[i]->is_alive = true;
        data->ennemies->skeleton[i]->pos = pos;
        data->ennemies->skeleton[i]->life = 100;
    }
}
