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

void display_npc(data_t *data)
{
    npc_t *node = data->npc;

    while (node != NULL) {
        if (node->active) {
            sfRenderWindow_drawSprite(data->window, node->sprite, NULL);
            npc_animation(node);
        }
        node = node->next;
    }
}
