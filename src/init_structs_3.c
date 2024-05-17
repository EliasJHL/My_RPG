/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void init_text(data_t *data)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    data->text = malloc(sizeof(text_t));
    data->text->talk = sfText_create();
    data->text->open_chest = sfText_create();
    sfText_setFont(data->text->talk, font);
    sfText_setFont(data->text->open_chest, font);
    sfText_setColor(data->text->talk, sfWhite);
    sfText_setColor(data->text->open_chest, sfWhite);
    sfText_setCharacterSize(data->text->talk, 60);
    sfText_setCharacterSize(data->text->open_chest, 60);
    sfText_setScale(data->text->talk, (sfVector2f){0.2, 0.2});
    sfText_setScale(data->text->open_chest, (sfVector2f){0.2, 0.2});
}

void init_bubble_text(data_t *data)
{
    sfColor bg = sfColor_fromRGBA(0, 0, 0, 200);
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    data->bubble_text = malloc(sizeof(bubble_text_t));
    data->bubble_text->writing = false;
    data->bubble_text->bubble = sfRectangleShape_create();
    data->bubble_text->text = sfText_create();
    data->bubble_text->name = sfText_create();
    data->bubble_text->clock = sfClock_create();
    sfRectangleShape_setFillColor(data->bubble_text->bubble, bg);
    sfRectangleShape_setSize(data->bubble_text->bubble, (sfVector2f){300, 70});
    sfText_setCharacterSize(data->bubble_text->text, 60);
    sfText_setCharacterSize(data->bubble_text->name, 50);
    sfText_setFont(data->bubble_text->text, font);
    sfText_setFont(data->bubble_text->name, font);
    sfText_setColor(data->bubble_text->text, sfWhite);
    sfText_setColor(data->bubble_text->name, sfWhite);
    sfText_setScale(data->bubble_text->text, (sfVector2f){0.3, 0.3});
    sfText_setScale(data->bubble_text->name, (sfVector2f){0.4, 0.4});
}
