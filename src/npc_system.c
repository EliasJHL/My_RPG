/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void npc_animation(npc_t *npc)
{
    double seconds;
    int nb = npc->nb_frames;

    npc->elapsed_time = sfClock_getElapsedTime(npc->clock);
    seconds = sfTime_asSeconds(npc->elapsed_time);
    if (seconds >= 0.15) {
        npc->rect.top = 0;
        npc->rect.left += 48;
        npc->rect.height = 48;
        npc->rect.width = 48;
        if (npc->rect.left >= npc->rect.width * nb) {
            npc->rect.left = 0;
        }
        sfClock_restart(npc->clock);
        sfSprite_setTextureRect(npc->sprite, npc->rect);
    }
}

void priority_display_npc(data_t *data)
{
    npc_t *node = data->npc;
    npc_t *node_2 = data->npc;

    while (node != NULL) {
        if (node->pos.y < data->player->player_pos.y && data->tuto_mode ==
            node->is_tuto)
            sfRenderWindow_drawSprite(data->window, node->sprite, NULL);
        node = node->next;
    }
    sfRenderWindow_drawSprite(data->window,
        data->player->player_sprite, NULL);
    while (node_2 != NULL) {
        if (node_2->pos.y >= data->player->player_pos.y && data->tuto_mode ==
            node_2->is_tuto)
            sfRenderWindow_drawSprite(data->window, node_2->sprite, NULL);
        node_2 = node_2->next;
    }
}

void display_npc(data_t *data)
{
    npc_t *node = data->npc;
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - 180, center.y + 170};

    while (node != NULL) {
        if (node->active) {
            priority_display_npc(data);
            npc_animation(node);
        }
        node = node->next;
    }
    sfText_setString(data->text->talk, "Press E to talk");
    sfText_setPosition(data->text->talk, sprite_pos);
    sfRenderWindow_drawText(data->window, data->text->talk, NULL);
}
