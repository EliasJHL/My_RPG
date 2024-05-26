/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void update_position_mini_quest(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f pos = {center.x - 1920 / 2, center.y - 1080 / 2};

    sfRectangleShape_setPosition(data->quests_display->mini_banner,
        (sfVector2f) {pos.x + 502, pos.y + 385});
    sfText_setPosition(data->quests_display->title,
        (sfVector2f) {pos.x + 513, pos.y + 395});
    sfText_setPosition(data->quests_display->description,
        (sfVector2f) {pos.x + 513, pos.y + 410});
    sfRectangleShape_setPosition(data->quests_display->prog_bar,
        (sfVector2f) {pos.x + 512, pos.y + 435});
    sfRectangleShape_setPosition(data->quests_display->prog_bar_bg,
        (sfVector2f) {pos.x + 512, pos.y + 435});
}

void set_text(data_t *data, int id)
{
    sfText_setString(data->quests_display->title,
        "Kill 5 slimes");
    sfText_setString(data->quests_display->description,
        "Find a slime sector and kill 5 of them");
    sfText_setString(data->quests_display->progression,
        "0/5");
}

void draw_mini_quest(data_t *data)
{
    sfRenderWindow_drawRectangleShape(data->window,
        data->quests_display->mini_banner, NULL);
    sfRenderWindow_drawText(data->window, data->quests_display->title, NULL);
    sfRenderWindow_drawText(data->window,
        data->quests_display->description, NULL);
    sfRenderWindow_drawRectangleShape(data->window,
        data->quests_display->prog_bar_bg, NULL);
    sfRenderWindow_drawRectangleShape(data->window,
        data->quests_display->prog_bar, NULL);
}

void display_mini_quest(data_t *data, int id)
{
    if (data->player->doing_quest) {
        update_position_mini_quest(data);
        set_text(data, id);
        draw_mini_quest(data);
    }
}
