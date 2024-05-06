/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void item_system_inventory(data_t *data)
{
    items_t *current = data->items;

    while (current != NULL) {
        if (is_clicked(data, current->item))
            printf("Item clicked\n");
        current = current->next;
    }
}
