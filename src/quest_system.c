/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

quest_t *get_quest(data_t *data, int id)
{
    quest_t *tmp = data->quests;

    while (tmp != NULL) {
        if (tmp->id == id)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

static void set_opacity(data_t *data, int opacity)
{
    sfRectangleShape_setFillColor(data->quests_display->banner,
        (sfColor){0, 0, 0, opacity});
    sfText_setColor(data->quests_display->title_full,
        (sfColor){255, 255, 255, opacity});
    sfText_setColor(data->quests_display->description_full,
        (sfColor){255, 255, 255, opacity});
}

static void set_text_banner(data_t *data, quest_t *tmp)
{
    sfText_setString(data->quests_display->title_full, tmp->title_full);
    sfText_setString(data->quests_display->description_full,
        tmp->description_full);
}

static void draw_elements_banner(data_t *data)
{
    sfRenderWindow_drawRectangleShape(data->window,
        data->quests_display->banner, NULL);
    sfRenderWindow_drawText(data->window,
        data->quests_display->title_full, NULL);
    sfRenderWindow_drawText(data->window,
        data->quests_display->description_full, NULL);
}

void update_position_quest(data_t *data)
{
    quest_t *tmp = get_quest(data, data->player->quest_id);
    sfFloatRect title_rect = sfText_getGlobalBounds(
        data->quests_display->title_full);
    sfFloatRect desc_rect = sfText_getGlobalBounds(
        data->quests_display->description_full);
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f pos = {center.x - 1920 / 2, center.y - 1080 / 2};

    sfRectangleShape_setPosition(data->quests_display->banner,
        (sfVector2f) {pos.x, pos.y + 370});
    sfText_setPosition(data->quests_display->title_full,
        (sfVector2f) {pos.x + 960 - (title_rect.width * 0.5), pos.y + 395});
    sfText_setPosition(data->quests_display->description_full,
        (sfVector2f) {pos.x + 960 - (desc_rect.width * 0.5), pos.y + 430});
    set_text_banner(data, tmp);
}

int display_banner_2(data_t *data, int opacity, double seconds)
{
    static int mode = 0;

    if (seconds >= 0.01 && opacity < 200 && mode == 0) {
        opacity += 5;
        set_opacity(data, opacity);
    }
    if (seconds >= 5 && opacity == 200 && mode == 0) {
        mode = 1;
        sfClock_restart(data->quests_display->clock);
    }
    if (seconds >= 0.01 && opacity > 0 && mode == 1) {
        opacity -= 5;
        set_opacity(data, opacity);
    }
    if (seconds >= 1 && opacity == 0 && mode == 1) {
        data->quests_display->banner_available = false;
        sfClock_restart(data->quests_display->clock);
    }
    return opacity;
}

void display_banner(data_t *data)
{
    double seconds;
    static int opacity = 0;

    update_position_quest(data);
    if (data->quests_display->banner_available == false)
        return;
    data->quests_display->elapsed_time = sfClock_getElapsedTime(
        data->quests_display->clock);
    seconds = sfTime_asSeconds(data->quests_display->elapsed_time);
    opacity = display_banner_2(data, opacity, seconds);
    draw_elements_banner(data);
    data->hud_state = 0;
}

void give_quest(data_t *data, int id)
{
    quest_t *tmp = data->quests;

    while (tmp != NULL) {
        if (tmp->id == id && tmp->is_active) {
            data->player->doing_quest = true;
            data->player->quest_id = id;
            data->quests_display->banner_available = true;
            break;
        }
        tmp = tmp->next;
    }
}
