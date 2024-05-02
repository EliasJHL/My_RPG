/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** The_Boss
*/

#include "../include/my.h"

//Initialisation of the boss statut
void draw_boss(boss_t *boss)
{
    sfTexture *boss_texture;

    boss_texture = sfTexture_createFromFile("assets/human.png", NULL);
    boss->boss_sprite = sfSprite_create();
    sfSprite_setTexture(boss->boss_sprite, boss_texture, sfTrue);
}

void boss_basic(boss_t *boss)
{
    sfVector2f boss_pos = {0, 0};
    sfVector2f boss_scale = {2, 2};

    draw_boss(boss);
    sfSprite_setPosition(boss->boss_sprite, boss_pos);
    sfSprite_setScale(boss->boss_sprite, boss_scale);
}
