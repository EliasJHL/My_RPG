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
    newNode->active = true;
    newNode->clock = sfClock_create();
    newNode->next = NULL;
    newNode->to_talk = true;
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
    txt = sfTexture_createFromFile(path, NULL);
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

static void config_txt(char *path, npc_t *newNode)
{
    sfTexture *txt = NULL;

    txt = sfTexture_createFromFile(path, NULL);
    if (txt == NULL) {
        txt = sfTexture_createFromFile("assets/npcs/none_talk.png", NULL);
        sfSprite_setTexture(newNode->talk_sprite, txt, sfTrue);
    } else {
        sfSprite_setTexture(newNode->talk_sprite, txt, sfTrue);
    }
    free(txt);
}

static void config_npc(char *name, data_t *data, bool is_tuto)
{
    char *path = malloc(sizeof("assets/npcs/") + sizeof(name) + 10);
    npc_t *node = data->npc;

    strcpy(path, "assets/npcs/");
    strcat(path, name);
    strcat(path, "_talk.png");
    while (node != NULL) {
        if (strcmp(node->npc_name, name) == 0) {
            node->talk_sprite = sfSprite_create();
            config_txt(path, node);
            node->to_talk = true;
            node->is_tuto = is_tuto;
        }
        node = node->next;
    }
    free(path);
}

void init_npc_2(data_t *data)
{
    config_npc("jean", data, true);
}

void init_npc(data_t *data)
{
    add_npc(data, "jean", (sfVector2f){855, 900}, 6);
    init_npc_2(data);
}
