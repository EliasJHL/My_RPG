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

void display_text(data_t *data, npc_t *npc)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f pos = {center.x, center.y + 100};

    sfRectangleShape_setPosition(data->bubble_text->bubble,
        (sfVector2f){pos.x - 150, pos.y});
    sfText_setString(data->text->talk, "Hello world !");
    sfText_setPosition(data->text->talk, pos);
    sfRenderWindow_drawRectangleShape(data->window,
        data->bubble_text->bubble, NULL);
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
        if (CHECK_NPC(npc->pos, data->player->player_pos, 30)){
            detect_process(data, npc);
        } else {
            data->player->is_talking = false;
        }
        npc = npc->next;
    }
}
