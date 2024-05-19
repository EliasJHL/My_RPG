/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static drop_items_t *cooldown_recoverable(data_t *data, drop_items_t *current)
{
    sfTime time = sfClock_getElapsedTime(current->clock);
    float seconds = sfTime_asSeconds(time);
    drop_items_t *tmp = NULL;
    drop_items_t *next = current->next;

    if (seconds > 5 && seconds < 10)
        current->is_recoverable = true;
    if (seconds > 600) {
        tmp = data->drop_items;
        while (tmp != NULL && tmp->next != current)
            tmp = tmp->next;
        if (tmp != NULL)
            tmp->next = next;
        else
            data->drop_items = next;
        free(current);
    }
    return next;
}

static void display_item_sprite(data_t *data, int id, sfVector2f pos)
{
    items_t *current = data->items;
    sfVector2f s;

    while (current != NULL) {
        if (current->item_id == id) {
            s = sfSprite_getScale(current->item);
            sfSprite_setPosition(current->item, pos);
            sfSprite_setScale(current->item, (sfVector2f){s.x / 2, s.y / 2});
            sfRenderWindow_drawSprite(data->window, current->item, NULL);
            sfSprite_setScale(current->item, s);
            return;
        }
        current = current->next;
    }
}

void display_drop_item(data_t *data)
{
    drop_items_t *current = data->drop_items;

    while (current != NULL) {
        display_item_sprite(data, current->id, current->pos);
        current = cooldown_recoverable(data, current);
    }
}

void drop_item(data_t *data, int id)
{
    drop_items_t *new = malloc(sizeof(drop_items_t));
    drop_items_t *current = data->drop_items;
    sfVector2f pos = data->player->player_pos;

    new->id = id;
    new->clock = sfClock_create();
    new->pos = (sfVector2f){pos.x + 20, pos.y + 20};
    new->is_recoverable = false;
    new->next = NULL;
    if (current == NULL) {
        data->drop_items = new;
    } else {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }
}
