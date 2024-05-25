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
        (sfVector2f) {pos.x + 502, pos.y + 385});
    sfText_setPosition(data->quests_display->description,
        (sfVector2f) {pos.x + 502, pos.y + 420});
}

void debug_text(data_t *data)
{
    sfText_setString(data->quests_display->title,
        "Find the lost dog");
    sfText_setString(data->quests_display->description,
        "The dog");
}

void display_mini_quest(data_t *data)
{
    update_position_mini_quest(data);
    debug_text(data);
    sfRenderWindow_drawRectangleShape(data->window,
        data->quests_display->mini_banner, NULL);
    sfText_setString(data->quests_display->title,
        "Find the lost dog");
    sfText_setString(data->quests_display->description,
        "The dog");
}
