/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void display_buuble(data_t *data, npc_t *npc)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f pos = {center.x, center.y + 100};
    sfVector2f name_pos = {center.x - 140, center.y + 80};

    sfText_setString(data->bubble_text->name, npc->npc_name);
    sfText_setPosition(data->bubble_text->name, name_pos);
    sfRectangleShape_setPosition(data->bubble_text->bubble,
        (sfVector2f){pos.x - 150, pos.y});
    sfRenderWindow_drawRectangleShape(data->window,
        data->bubble_text->bubble, NULL);
    sfRenderWindow_drawText(data->window, data->bubble_text->name, NULL);
}

static void handle_dialog(data_t *data, npc_t *npc)
{
    data->dialog_finished = true;
    if (data->dialog_finished == true) {
        if (npc->is_sign == true)
            data->player->is_talking = false;
        data->player->available = true;
        data->sign_display = true;
    }
}

static void text_process(char *text, char *str, int i, int len)
{
    for (int j = 0; j <= i && j < len; j++)
        text[j] = str[j];
    if (i < len)
        text[i + 1] = '\0';
    else
        text[len] = '\0';
}

void text_writer(data_t *data, char *str, npc_t *npc)
{
    static int i = 0;
    size_t len = strlen(str);
    char *text = malloc(sizeof(char) * (len + 1));
    double seconds = 0;

    seconds = sfTime_asSeconds(data->bubble_text->elapsed_time);
    if (seconds >= 0.08) {
        text_process(text, str, i, len);
        sfText_setString(data->bubble_text->text, text);
        sfClock_restart(data->bubble_text->clock);
        if (str[i] == '\0') {
            i = 0;
            handle_dialog(data, npc);
        } else {
            i++;
            data->dialog_finished = false;
        }
    }
    free(text);
}

void sign_text(data_t *data, npc_t *npc)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f dialogue_pos = {center.x - 140, center.y + 110};

    sfText_setPosition(data->bubble_text->text, dialogue_pos);
    sfRenderWindow_drawText(data->window, data->bubble_text->name, NULL);
    data->bubble_text->elapsed_time = sfClock_getElapsedTime(
            data->bubble_text->clock);
    if (data->sign_display)
        text_writer(data, npc->txt_sign, npc);
    sfRenderWindow_drawText(data->window, data->bubble_text->text, NULL);
}

void display_simple_text(data_t *data, npc_t *npc, char *str)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f dialogue_pos = {center.x - 140, center.y + 110};

    sfText_setPosition(data->bubble_text->text, dialogue_pos);
    sfRenderWindow_drawText(data->window, data->bubble_text->name, NULL);
    sfText_setString(data->bubble_text->text, str);
    sfRenderWindow_drawText(data->window, data->bubble_text->text, NULL);
}

void npc_text(data_t *data, npc_t *npc, char *str)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f dialogue_pos = {center.x - 140, center.y + 110};

    sfText_setPosition(data->bubble_text->text, dialogue_pos);
    sfRenderWindow_drawText(data->window, data->bubble_text->name, NULL);
    data->bubble_text->elapsed_time = sfClock_getElapsedTime(
            data->bubble_text->clock);
    text_writer(data, str, npc);
    sfRenderWindow_drawText(data->window, data->bubble_text->text, NULL);
}
