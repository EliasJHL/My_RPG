/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void draw_talk_text(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - 180, center.y + 170};

    sfText_setString(data->text->talk, "Press F to talk");
    sfText_setPosition(data->text->talk, sprite_pos);
    sfRenderWindow_drawText(data->window, data->text->talk, NULL);
}

static void text_writer(data_t *data, char *str)
{
    static int i = 0;
    char *text = malloc(sizeof(char) * (strlen(str) + 1));
    double seconds = 0;

    seconds = sfTime_asSeconds(data->bubble_text->elapsed_time);
    if (seconds >= 0.08) {
        for (int j = 0; j <= i; j++)
            text[j] = str[j];
        text[i + 1] = '\0';
        sfText_setString(data->bubble_text->text, text);
        sfClock_restart(data->bubble_text->clock);
        if (str[i] == '\0') {
            data->bubble_text->writing = false;
            i = 0;
        } else {
            i++;
        }
    }
    sfRenderWindow_drawText(data->window, data->bubble_text->text, NULL);
}

void display_text(data_t *data, npc_t *npc)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f pos = {center.x, center.y + 100};
    sfVector2f dialogue_pos = {center.x - 140, center.y + 110};
    sfVector2f name_pos = {center.x - 140, center.y + 80};

    sfRectangleShape_setPosition(data->bubble_text->bubble,
        (sfVector2f){pos.x - 150, pos.y});
    sfRenderWindow_drawRectangleShape(data->window,
        data->bubble_text->bubble, NULL);
    sfText_setPosition(data->bubble_text->text, dialogue_pos);
    sfText_setPosition(data->bubble_text->name, name_pos);
    sfText_setString(data->bubble_text->name, npc->npc_name);
    sfRenderWindow_drawText(data->window, data->bubble_text->name, NULL);
    data->bubble_text->elapsed_time = sfClock_getElapsedTime(
            data->bubble_text->clock);
    text_writer(data, "Hey welcome in the pixel world\nadventurer!");
}

void detect_process(data_t *data, npc_t *npc)
{
    if (data->player->is_talking == false)
        draw_talk_text(data);
    if (sfKeyboard_isKeyPressed(sfKeyF) && data->tuto_mode == npc->is_tuto)
        data->player->is_talking = true;
    if (data->player->is_talking == true)
        display_text(data, npc);
}

void detect_npc(data_t *data)
{
    npc_t *npc = data->npc;

    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, data->player->player_pos, 30)) {
            detect_process(data, npc);
        } else {
            data->player->is_talking = false;
            data->bubble_text->writing = false;
        }
        npc = npc->next;
    }
}
