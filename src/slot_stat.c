/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

items_t *get_item(data_t *data, int id)
{
    items_t *current = data->items;

    while (current != NULL) {
        if (current->item_id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void set_stat(data_t *data, int i)
{
    items_t *current = get_item(data, data->inv->slots[i].item_id);

    if (current == NULL)
        return;
    if (strcmp(current->item_type, "attack") == 0)
        data->player->attack_stat += current->item_value;
    if (strcmp(current->item_type, "defense") == 0)
        data->player->defense_stat += current->item_value;
}

void display_slots_stat(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - 195, center.y - 30};
    int status = 0;

    data->player->attack_stat = 10;
    data->player->defense_stat = 10;
    for (int i = 48; i < 52; i++) {
        sprite_pos.x += 30;
        if (sprite_pos.x >= center.x + 180) {
            sprite_pos.x = center.x - 180;
            sprite_pos.y += 30;
        }
        sfRectangleShape_setOutlineThickness(data->inv->slots[i].slot, 2);
        sfRectangleShape_setOutlineColor(data->inv->slots[i].slot, sfRed);
        sfRectangleShape_setPosition(data->inv->slots[i].slot, sprite_pos);
        conditions_check_1(data, i, sprite_pos);
        set_stat(data, i);
        data->selected_id = 0;
    }
}
