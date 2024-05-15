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
