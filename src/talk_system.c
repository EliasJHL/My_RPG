/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void draw_talk_text(data_t *data, npc_t *npc)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - 180, center.y + 170};
    char *str = NULL;

    if (npc->is_sign == true) {
        sfText_setString(data->text->talk, "Press F to read");
    } else {
        str = malloc(sizeof(char *) * strlen("Press F to talk")
            + strlen(npc->npc_name) + 1);
        strcpy(str, "Press F to talk to ");
        strcat(str, npc->npc_name);
        sfText_setString(data->text->talk, str);
        free(str);
    }
    sfText_setPosition(data->text->talk, sprite_pos);
    sfRenderWindow_drawText(data->window, data->text->talk, NULL);
}

void detect_process_2(data_t *data, npc_t *npc)
{
    display_buuble(data, npc);
    if (npc->is_sign == true) {
        sign_text(data, npc);
    } else {
        npc_text(data, npc, npc->dialog[npc->dialog_count]);
        if (data->dialog_finished == true) {
            npc->dialog_count++;
            data->dialog_finished = false;
        }
        if (npc->dialog_count > npc->nb_dialog - 1) {
            npc->dialog_count = 0;
            data->player->is_talking = false;
        }
    }
}

void detect_process(data_t *data, npc_t *npc)
{
    if (data->player->is_talking == false)
        draw_talk_text(data, npc);
    if (sfKeyboard_isKeyPressed(sfKeyF) &&
        data->tuto_mode == npc->is_tuto) {
        data->player->is_talking = true;
        data->player->available = false;
    }
    if (data->player->is_talking == true) {
        detect_process_2(data, npc);
    }
}

static void check_not_talk(data_t *data)
{
    if (data->player->available) {
        sfText_setString(data->text->talk, "");
        data->sign_display = true;
        data->bubble_text->writing = false;
        data->sign_display = true;
    } else {
        return;
    }
}

void detect_npc(data_t *data)
{
    npc_t *npc = data->npc;

    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, data->player->player_pos, 30)) {
            detect_process(data, npc);
        } else {
            check_not_talk(data);
            npc->dialog_count = 0;
        }
        npc = npc->next;
    }
}
