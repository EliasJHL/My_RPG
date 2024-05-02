/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void test_texture(char *name, items_t *newNode)
{
    char *path = malloc(strlen("assets/items/") + strlen(name) + 1);
    sfTexture *txt = NULL;

    strcpy(path, "assets/items/");
    strcat(path, name);
    txt = sfTexture_createFromFile(path, NULL);
    if (txt == NULL) {
        free(path);
        txt = sfTexture_createFromFile("assets/items/none.png", NULL);
        sfSprite_setTexture(newNode->item, txt, sfTrue);
        free(txt);
    } else {
        free(path);
        sfSprite_setTexture(newNode->item, txt, sfTrue);
        free(txt);
    }
}

void add_new_node(char *line, items_t *newNode)
{
    sfFloatRect s;

    newNode->item = sfSprite_create();
    newNode->item_name = strdup(strtok(line, ":"));
    newNode->item_type = strdup(strtok(NULL, ":"));
    newNode->item_value = atoi(strtok(NULL, ":"));
    newNode->item_max_amount = atoi(strtok(NULL, ":"));
    newNode->item_id = atoi(strtok(NULL, ":"));
    test_texture(strtok(NULL, ":"), newNode);
    s = sfSprite_getGlobalBounds(newNode->item);
    s.width = 25 / s.width;
    s.height = 25 / s.height;
    sfSprite_setScale(newNode->item, (sfVector2f){s.width, s.height});
    newNode->price = atoi(strtok(NULL, ":"));
    newNode->in_inventory = sfFalse;
    newNode->next = NULL;
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
