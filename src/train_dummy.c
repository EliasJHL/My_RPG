/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** init train for tutorial
*/

#include "../include/my.h"

static void init_train1(train_t *train)
{
    sfTexture *train_texture;

    train_texture = sfTexture_createFromFile(TEXT_TRAIN, NULL);
    train->sprite = sfSprite_create();
    sfSprite_setTexture(train->sprite, train_texture, sfTrue);
    train->pos = (sfVector2f){0, 0};
    sfSprite_setPosition(train->sprite, train->pos);
    sfSprite_setScale(train->sprite, (sfVector2f){2, 2});
    free(train_texture);
}

static void init_train2(train_t *train)
{
    train->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(train->hitbox, (sfVector2f){14, 14});
    sfRectangleShape_setFillColor(train->hitbox, sfTransparent);
    sfRectangleShape_setOutlineThickness(train->hitbox, 1);
    sfRectangleShape_setOutlineColor(train->hitbox, sfRed);
}
