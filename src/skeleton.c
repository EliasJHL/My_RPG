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
        sfSprite_setTextureRect(SKELETON->sprite, (sfIntRect){0, 0, 32, 32});
        sfSprite_setScale(SKELETON->sprite, (sfVector2f){1, 1});
        SKELETON->is_alive = false;
        SKELETON->hitbox = sfRectangleShape_create();
        sfRectangleShape_setSize(SKELETON->hitbox, (sfVector2f){14, 14});
        sfRectangleShape_setFillColor(SKELETON->hitbox, sfTransparent);
        sfRectangleShape_setOutlineThickness(SKELETON->hitbox, 1);
        sfRectangleShape_setOutlineColor(SKELETON->hitbox, sfRed);
    }
    free(txt);
}
