/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void set_scale(data_t *data)
{
    sfText_setScale(data->quests_display->title, (sfVector2f){0.5, 0.5});
    sfText_setScale(data->quests_display->description,
        (sfVector2f){0.35, 0.35});
    sfText_setScale(data->quests_display->progression, (sfVector2f){0.5, 0.5});
    sfText_setScale(data->quests_display->title_full, (sfVector2f){0.5, 0.5});
    sfText_setScale(data->quests_display->description_full,
        (sfVector2f){0.3, 0.3});
}

void set_font(data_t *data)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfText_setFont(data->quests_display->title, font);
    sfText_setFont(data->quests_display->description, font);
    sfText_setFont(data->quests_display->progression, font);
    sfText_setFont(data->quests_display->title_full, font);
    sfText_setFont(data->quests_display->description_full, font);
    sfText_setCharacterSize(data->quests_display->title, 20);
    sfText_setCharacterSize(data->quests_display->description, 20);
    sfText_setCharacterSize(data->quests_display->progression, 50);
    sfText_setCharacterSize(data->quests_display->title_full, 40);
    sfText_setCharacterSize(data->quests_display->description_full, 40);
    sfText_setColor(data->quests_display->title, sfWhite);
    sfText_setColor(data->quests_display->description, sfWhite);
    sfText_setColor(data->quests_display->progression, sfWhite);
    sfText_setColor(data->quests_display->title_full, sfWhite);
    sfText_setColor(data->quests_display->description_full, sfWhite);
}

static void set_rectangles_color(data_t *data)
{
    sfColor color = {0, 0, 0, 100};
    sfColor color2 = {255, 255, 255, 255};
    sfColor color3 = {150, 150, 150, 200};
    sfColor color4 = {0, 0, 0, 255};

    sfRectangleShape_setFillColor(data->quests_display->mini_banner, color);
    sfRectangleShape_setFillColor(data->quests_display->prog_bar, color2);
    sfRectangleShape_setFillColor(data->quests_display->prog_bar_bg, color3);
    sfRectangleShape_setFillColor(data->quests_display->banner, color4);
}

void create_rectangles(data_t *data)
{
    data->quests_display->mini_banner = sfRectangleShape_create();
    data->quests_display->prog_bar = sfRectangleShape_create();
    data->quests_display->prog_bar_bg = sfRectangleShape_create();
    data->quests_display->banner = sfRectangleShape_create();
    sfRectangleShape_setSize(data->quests_display->mini_banner,
        (sfVector2f){180, 60});
    sfRectangleShape_setSize(data->quests_display->prog_bar,
        (sfVector2f){160, 1});
    sfRectangleShape_setSize(data->quests_display->prog_bar_bg,
        (sfVector2f){160, 1});
    sfRectangleShape_setSize(data->quests_display->banner,
        (sfVector2f){1920, 100});
    set_rectangles_color(data);
}

void init_mini_display(data_t *data)
{
    data->quests_display = malloc(sizeof(quest_display_t));
    data->quests_display->title = sfText_create();
    data->quests_display->description = sfText_create();
    data->quests_display->progression = sfText_create();
    data->quests_display->title_full = sfText_create();
    data->quests_display->description_full = sfText_create();
    data->quests_display->clock = sfClock_create();
    set_font(data);
    set_scale(data);
    create_rectangles(data);
}
