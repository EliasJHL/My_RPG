/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void drop_item_npc_config(data_t *data, char *name, bool drop_item, int id)
{
    npc_t *node = data->npc;

    while (node != NULL) {
        if (strcmp(node->npc_name, name) == 0) {
            node->drop_item = drop_item;
            node->item_id = id;
        }
        node = node->next;
    }
}

void quest_npc_config(data_t *data, char *name, bool has_quest, int id)
{
    npc_t *node = data->npc;

    while (node != NULL) {
        if (strcmp(node->npc_name, name) == 0) {
            node->give_quest = has_quest;
            node->quest_id = id;
        }
        node = node->next;
    }
}

//For drop item
void init_npc_4(data_t *data)
{
    drop_item_npc_config(data, "john", false, 0);
    drop_item_npc_config(data, "pierre", true, 1);
    drop_item_npc_config(data, "pierrik the fisherman", true, 7);
    drop_item_npc_config(data, "lumberjack", true, 12);
    drop_item_npc_config(data, "villager", false, 0);
    drop_item_npc_config(data, "Angel", false, 0);
}

//For quests
void init_npc_3(data_t *data)
{
    quest_npc_config(data, "john", true, 0);
    quest_npc_config(data, "pierre", true, 0);
    quest_npc_config(data, "pierrik the fisherman", true, 0);
    quest_npc_config(data, "lumberjack", false, 0);
    quest_npc_config(data, "villager", false, 0);
    quest_npc_config(data, "Angel", false, 0);
    init_npc_4(data);
}
