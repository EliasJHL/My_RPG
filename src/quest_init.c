/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

char *open_config_file(void)
{
    char *buffer = malloc(sizeof(char) * 1000);
    size_t n = 0;
    FILE *fd = fopen("config_files/quests/quests.config", "r");

    n = fread(buffer, 1, 1000, fd);
    buffer[n] = '\0';
    fclose(fd);
    return buffer;
}

void set_data_node(quest_t *node, char *line, data_t *data, quest_t *last)
{
    node = malloc(sizeof(quest_t));
    node->id = atoi(strtok(line, ":\n"));
    node->banner_name = strtok(NULL, ":\n");
    node->title_full = strtok(NULL, ":\n");
    node->description_full = strtok(NULL, ":\n");
    node->title_short = strtok(NULL, ":\n");
    node->description_short = strtok(NULL, ":\n");
    node->has_reward = atoi(strtok(NULL, ":\n"));
    node->item_reward = atoi(strtok(NULL, ":\n"));
    node->is_tutorial = atoi(strtok(NULL, ":\n"));
    node->has_progression = atoi(strtok(NULL, ":\n"));
    node->progression_count = atoi(strtok(NULL, ":\n"));
    node->progression_goal = atoi(strtok(NULL, ":\n"));
    node->is_active = atoi(strtok(NULL, ":\n"));
    if (data->quests == NULL) {
        data->quests = node;
    } else {
        last->next = node;
    }
    last = node;
}

void init_quest(data_t *data)
{
    char *buffer = open_config_file();
    char *line = NULL;
    quest_t *node = NULL;
    quest_t *last = NULL;

    line = strtok(buffer, "\n\0");
    while (line != NULL) {
        if (line[0] != '#') {
            set_data_node(node, line, data, last);
        }
        line = strtok(NULL, "\n\0");
    }
    free(buffer);
}
