/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void set_npc_info_2(npc_t *newNode, char *name, sfVector2f pos, int nb)
{
    sfSprite_setPosition(newNode->sprite, pos);
    newNode->npc_name = name;
    newNode->pos = pos;
    newNode->nb_frames = nb;
    newNode->next = NULL;
}

npc_t *set_npc_info(char *name, sfVector2f pos, int nb)
{
    npc_t *newNode = malloc(sizeof(npc_t));
    char *path = malloc(sizeof("assets/items") + sizeof(name) + 6);
    sfTexture *txt = NULL;

    strcpy(path, "assets/npcs/");
    strcat(path, name);
    strcat(path, ".png");
    newNode->sprite = sfSprite_create();
    txt = sfTexture_createFromFile("assets/npcs/jean.png", NULL);
    if (txt == NULL) {
        txt = sfTexture_createFromFile("assets/npcs/none.png", NULL);
        sfSprite_setTexture(newNode->sprite, txt, sfTrue);
    } else {
        sfSprite_setTexture(newNode->sprite, txt, sfTrue);
    }
    set_npc_info_2(newNode, name, pos, nb);
    free(txt);
    free(path);
    return newNode;
}

// the name of npc need to be the same of
// his texture name (jean → jean.png on assets/npcs)
void add_npc(data_t *data, char *name, sfVector2f pos, int nb_frames)
{
    npc_t *node = data->npc;

    if (node == NULL)
        data->npc = set_npc_info(name, pos, nb_frames);
    else {
        while (node->next != NULL)
            node = node->next;
        node->next = set_npc_info(name, pos, nb_frames);
    }
}

void init_npc(data_t *data)
{
    add_npc(data, "jean", (sfVector2f){100, 100}, 4);
    add_npc(data, "sus", (sfVector2f){200, 200}, 4);
}
