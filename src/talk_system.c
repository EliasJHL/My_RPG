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

void finish_talk_check(data_t *data, npc_t *npc)
{
    npc->dialog_count = 0;
    if (npc->drop_item) {
        drop_item(data, npc->item_id);
    }
    if (npc->give_quest) {
        give_quest(data, npc->quest_id);
    }
}

void detect_process_2(data_t *data, npc_t *npc)
{
    display_buuble(data, npc);
    if (npc->is_sign == true) {
        sign_text(data, npc);
    } else {
        if (npc->dialog_count > npc->nb_dialog - 1) {
            finish_talk_check(data, npc);
            return;
        }
        if (data->dialog_finished == true)
            display_simple_text(data, npc, npc->dialog[npc->dialog_count]);
        else
            npc_text(data, npc, npc->dialog[npc->dialog_count]);
        if (data->dialog_finished == true && sfKeyboard_isKeyPressed(sfKeyF)) {
            npc->dialog_count++;
            data->dialog_finished = false;
        }
    }
}

void detect_process(data_t *data, npc_t *npc)
{
    if (data->player->is_talking == false)
        draw_talk_text(data, npc);
    if (sfKeyboard_isKeyPressed(sfKeyF) &&
        data->tuto_mode == npc->is_tuto) {
        npc->talking = true;
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

int detect_if_talking(data_t *data, npc_t *npc)
{
    if (npc->talking)
        return 1;
    else
        return 0;
}

static void reset_all(data_t *data)
{
    npc_t *npc = data->npc;

    data->count_dialog = 0;
    while (npc != NULL) {
        npc->talking = false;
        npc->dialog_count = 0;
        sfClock_restart(npc->clock);
        npc = npc->next;
    }
}

static void check_if_npc(data_t *data)
{
    npc_t *detect = data->npc;
    int i = 0;

    while (detect != NULL) {
        i += detect_if_talking(data, detect);
        detect = detect->next;
    }
    if (i == 0) {
        data->player->is_talking = false;
        reset_all(data);
    }
}

void detect_npc(data_t *data)
{
    npc_t *npc = data->npc;

    check_if_npc(data);
    while (npc != NULL) {
        if (CHECK_NPC(npc->pos, data->player->player_pos, 30)) {
            detect_process(data, npc);
        } else {
            check_not_talk(data);
            npc->dialog_count = 0;
            npc->talking = false;
        }
        npc = npc->next;
    }
}
