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
    FILE *fd = fopen("config_files/quests/quests.config", "r");

    fread(buffer, 1, 1000, fd);
    fclose(fd);
    return buffer;
}

void init_quest(data_t *data)
{
    return;
}
