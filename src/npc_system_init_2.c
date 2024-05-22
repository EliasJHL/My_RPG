/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

char *get_npc_file(npc_t *node)
{
    char *path = malloc(sizeof("config_files/npcs_chat/") +
        sizeof(node->npc_name) + 5);
    FILE *fd = NULL;
    char *buffer = malloc(sizeof(char) * 1000);

    strcpy(path, "config_files/npcs_chat/");
    strcat(path, node->npc_name);
    strcat(path, ".txt");
    fd = fopen(path, "r");
    fread(buffer, 1, 1000, fd);
    free(path);
    fclose(fd);
    return buffer;
}

void config_dialog_npc(npc_t *node)
{
    char *buffer = get_npc_file(node);
    char *line = NULL;
    int i = 0;

    node->dialog = malloc(sizeof(char *) * 10);
    line = strtok(buffer, "\n");
    while (line != NULL) {
        node->dialog[i] = strdup(line);
        line = strtok(NULL, "\n");
        i++;
        node->nb_dialog++;
    }
    node->dialog[i] = NULL;
    free(buffer);
}
