/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void delete_item(data_t *data, drop_items_t *current)
{
    drop_items_t *tmp = data->drop_items;

    if (tmp == current) {
        data->drop_items = current->next;
        free(current);
        return;
    }
    while (tmp->next != current)
        tmp = tmp->next;
    tmp->next = current->next;
    free(current);
}

static drop_items_t *cooldown_recoverable(data_t *data, drop_items_t *current)
{
    sfTime time = sfClock_getElapsedTime(current->clock);
    float seconds = sfTime_asSeconds(time);
    drop_items_t *next = current->next;

    if (seconds > 5 && seconds < 10)
        current->is_recoverable = true;
    if (seconds > 600) {
        delete_item(data, current);
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

void add_item_to_inv(data_t *data, int id)
{
    for (int i = 0; i < 48; i++) {
        if (data->inv->slots[i].item_id == 0) {
            data->inv->slots[i].item_id = id;
            return;
        }
    }
    printf("Inventory is full\n");
}

static void recover_item_2(sfVector2f pos, data_t *data, drop_items_t *current)
{
    sfVector2f direction;
    float distance;
    float speed = 2.5;

    if (pos.x - current->pos.x < 50 && pos.y - current->pos.y < 50) {
        direction.x = pos.x - current->pos.x + 18;
        direction.y = pos.y - current->pos.y + 25;
        distance = sqrt(direction.x * direction.x +
            direction.y * direction.y);
        direction.x /= distance;
        direction.y /= distance;
        current->pos.x += direction.x * speed;
        current->pos.y += direction.y * speed;
        if (pos.x - current->pos.x < 0.2 && pos.y - current->pos.y < 0.2) {
            add_item_to_inv(data, current->id);
            delete_item(data, current);
        }
    }
}

void recover_item(data_t *data)
{
    drop_items_t *current = data->drop_items;
    sfVector2f pos = data->player->player_pos;

    while (current != NULL) {
        if (current->is_recoverable) {
            recover_item_2(pos, data, current);
        }
        current = current->next;
    }
}

void drop_item(data_t *data, int id)
{
    drop_items_t *new = malloc(sizeof(drop_items_t));
    drop_items_t *current = data->drop_items;
    sfVector2f pos = data->player->player_pos;
    int rand_x = (rand() % 30) + 10;
    int rand_y = (rand() % 30) + 10;

    new->id = id;
    new->clock = sfClock_create();
    new->pos = (sfVector2f){pos.x + rand_x, pos.y + rand_y};
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
