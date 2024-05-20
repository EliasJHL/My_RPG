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
        }
    }
    pos.x = PLAYER_X + 20;
    pos.y = data->player->player_pos.y + 31;
    sfRectangleShape_setPosition(data->player->hitbox, pos);
    if (sfFloatRect_intersects(&rect1, &rect2, &intersection))
        data->player->life -= 10;
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
