/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void init_slime(sfTexture *txt, ennemies_t *ennemies)
{
    for (int i = 0; i < 10; i++) {
        SLIME = malloc(sizeof(slime_t));
        SLIME->life = 100;
        SLIME->clock = sfClock_create();
        SLIME->sprite = sfSprite_create();
        sfSprite_setTexture(SLIME->sprite, txt, sfTrue);
        sfSprite_setTextureRect(SLIME->sprite, (sfIntRect){0, 0, 32, 32});
        sfSprite_setScale(SLIME->sprite, (sfVector2f){1, 1});
        SLIME->is_alive = false;
        SLIME->hitbox = sfRectangleShape_create();
        sfRectangleShape_setSize(SLIME->hitbox, (sfVector2f){14, 14});
        sfRectangleShape_setFillColor(SLIME->hitbox, sfTransparent);
        sfRectangleShape_setOutlineThickness(SLIME->hitbox, 1);
        sfRectangleShape_setOutlineColor(SLIME->hitbox, sfRed);
    }
}

//sfRenderWindow_drawRectangleShape(data->window, data->player->hitbox, NULL);
//sfRenderWindow_drawRectangleShape(data->window,
//data->ennemies->slime[i]->hitbox, NULL);
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
        }
    }
}

static void move_slime_player2(data_t *data, int i)
{
    int dir = (rand() % 4) + 1;

    if (dir == 1)
        SLIME_X += 0.3;
    if (dir == 2)
        SLIME_X -= 0.3;
    if (dir == 3)
        SLIME_Y += 0.3;
    if (dir == 4)
        SLIME_Y -= 0.3;
}

void move_slime_player(data_t *data, float distance, sfVector2f pos, int i)
{
    if (distance < 150) {
        if (SLIME_X < pos.x)
            SLIME_X += 0.3;
        if (SLIME_X > pos.x)
            SLIME_X -= 0.3;
        if (SLIME_Y < pos.y)
            SLIME_Y += 0.3;
        if (SLIME_Y > pos.y)
            SLIME_Y -= 0.3;
    } else {
        move_slime_player2(data, i);
    }
}

static void hit_slime(data_t *data, sfVector2f pos)
{
    sfFloatRect rect1;
    sfFloatRect rect2;
    sfFloatRect intersection;

    pos.x = PLAYER_X + 20;
    pos.y = PLAYER_Y + 31;
    sfRectangleShape_setPosition(data->player->hitbox, pos);
    rect1 = GLOBAL(data->player->hitbox);
    for (int i = 0; i < 10; i++) {
        rect2 = GLOBAL(data->ennemies->slime[i]->hitbox);
        if (sfFloatRect_intersects(&rect1, &rect2, &intersection) &&
            !data->player->damage_taken) {
            sfClock_restart(data->player->clock2);
            data->player->damage_taken = true;
            data->player->life -= 10;
        } else {
            timer_damage(data);
        }
    }
}

static void slime_animation(data_t *data, int i)
{
    double seconds;

    data->ennemies->slime[i]->elapsed_times = sfClock_getElapsedTime(
        data->ennemies->slime[i]->clock);
    seconds = sfTime_asSeconds(data->ennemies->slime[i]->elapsed_times);
    if (seconds > 0.15) {
        data->ennemies->slime[i]->rect.top = 64;
        data->ennemies->slime[i]->rect.left += 32;
        data->ennemies->slime[i]->rect.height = 32;
        data->ennemies->slime[i]->rect.width = 32;
        if (data->ennemies->slime[i]->rect.left >= 32 * 6)
            data->ennemies->slime[i]->rect.left = 0;
        sfClock_restart(data->ennemies->slime[i]->clock);
        sfSprite_setTextureRect(data->ennemies->slime[i]->sprite,
            data->ennemies->slime[i]->rect);
    }
}

void move_slime(data_t *data)
{
    float distance;
    sfVector2f pos = data->player->player_pos;
    sfFloatRect rect1 = GLOBAL(data->player->hitbox);
    sfFloatRect rect2 = GLOBAL(data->ennemies->slime[0]->hitbox);
    sfFloatRect intersection;

    pos.x += 9;
    pos.y += 19;
    for (int i = 0; i < 10; i++) {
        if (data->ennemies->slime[i]->is_alive == true) {
            distance = sqrt(pow(SLIME_X - PLAYER_X, 2) +
                            pow(SLIME_Y - PLAYER_Y, 2));
            move_slime_player(data, distance, pos, i);
            slime_animation(data, i);
        }
    }
    hit_slime(data, pos);
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
