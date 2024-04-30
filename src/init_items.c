/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

char *test_texture(char *name)
{
    char *path = strdup("assets/items/");

    strcat(path, name);
    if (access(path, F_OK) == 0) {
        free(path);
        return name;
    }
    free(path);
    return "none.png";
}

void add_new_node(char *line, items_t *newNode)
{
    char *sprite = strdup("assets/items/");
    sfTexture *txt = NULL;

    newNode->item = sfSprite_create();
    newNode->item_name = strdup(strtok(line, ":"));
    newNode->item_type = strdup(strtok(NULL, ":"));
    newNode->item_value = atoi(strtok(NULL, ":"));
    newNode->item_max_amount = atoi(strtok(NULL, ":"));
    newNode->item_id = atoi(strtok(NULL, ":"));
    strcat(sprite, test_texture(strtok(NULL, ":")));
    txt = sfTexture_createFromFile(sprite, NULL);
    sfSprite_setTexture(newNode->item, sfTexture_createFromFile(
        "assets/items/none.png", NULL), sfTrue);
    free(txt);
    sfSprite_setScale(newNode->item, (sfVector2f){0.1, 0.1});
    newNode->price = atoi(strtok(NULL, ":"));
    newNode->in_inventory = sfFalse;
    newNode->next = NULL;
    free(sprite);
}

void add_chained_list(data_t *data, char *line)
{
    items_t *current = data->items;
    items_t *newNode = malloc(sizeof(items_t));

    add_new_node(line, newNode);
    if (current == NULL) {
        data->items = newNode;
    } else {
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

int init_items(data_t *data)
{
    FILE *fp = fopen("config_files/items.config", "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL)
        return 84;
    while (getline(&line, &len, fp) != -1)
        if (line[0] != '#' && line[0] != '\n' && line[0] != '\0')
            add_chained_list(data, line);
    fclose(fp);
    return 0;
}
