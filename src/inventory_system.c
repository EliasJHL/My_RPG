/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void display_items_status(items_t *current, sfVector2f sprite_pos)
{
    if (!current->is_picked)
        sfSprite_setPosition(current->item, sprite_pos);
    else
        sfSprite_setPosition(current->item, current->item_pos);
}

static void display_items(data_t *data, sfVector2f sprite_pos, int id)
{
    items_t *current = data->items;

    while (current != NULL) {
        if (current->item_id == id) {
            display_items_status(current, sprite_pos);
            sfRenderWindow_drawSprite(data->window, current->item, NULL);
            return;
        }
        current = current->next;
    }
}

static int check_slot_click(data_t *data)
{
    for (int i = 0; i < 48; i++) {
        if (is_clicked_slot(data, data->inv->slots[i].slot)) {
            return i;
        }
    }
    return -1;
}

sfVector2f size_item(data_t *data, int i)
{
    items_t *current = data->items;
    sfFloatRect bounds;
    sfVector2f size;

    while (current != NULL) {
        if (current->item_id == i) {
            bounds = sfSprite_getGlobalBounds(current->item);
            size = (sfVector2f){bounds.width, bounds.height};
            return size;
        }
        current = current->next;
    }
    return (sfVector2f){0, 0};
}

static void item_selected_draw(data_t *data, sfVector2f mouse_pos, int i)
{
    items_t *current = data->items;

    while (current != NULL) {
        if (current->item_id == i) {
            data->inv->item_selected = current->item;
            sfSprite_setPosition(data->inv->item_selected, mouse_pos);
            data->inv->status = true;
            return;
        }
        current = current->next;
    }
}

void conditions_check_3(data_t *data, int i)
{
    sfVector2i mouse_pos_pixel;
    sfVector2f mouse_pos;
    sfVector2f size;

    if (data->inv->slots[i].selected == sfTrue) {
        mouse_pos_pixel = sfMouse_getPositionRenderWindow(data->window);
        mouse_pos = sfRenderWindow_mapPixelToCoords(data->window,
            mouse_pos_pixel, sfRenderWindow_getView(data->window));
        size = size_item(data, data->inv->slots[i].item_id);
        mouse_pos.x = mouse_pos.x - size.x / 2;
        mouse_pos.y = mouse_pos.y - size.y / 2;
        display_items(data, mouse_pos, data->inv->slots[i].item_id);
        data->selected_id = data->inv->slots[i].item_id;
    }
}

void conditions_check_2(data_t *data, int i)
{
    int id = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        !is_clicked_slot(data, data->inv->slots[i].slot)
        && data->inv->slots[i].selected == sfTrue) {
        data->selected_id = data->inv->slots[i].item_id;
        if (check_slot_click(data) == -1) {
            data->inv->slots[i].selected = sfFalse;
            data->inv->slots[i].item_id = data->selected_id;
        } else {
            id = check_slot_click(data);
            data->inv->slots[i].item_id = data->inv->slots[id].item_id;
            data->inv->slots[id].item_id = data->selected_id;
            data->inv->slots[i].selected = sfFalse;
            data->inv->slots[id].selected = sfFalse;
        }
    }
    conditions_check_3(data, i);
}

void conditions_check_1(data_t *data, int i, sfVector2f sprite_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        is_clicked_slot(data, data->inv->slots[i].slot)) {
        if (data->inv->slots[i].item_id != 0)
            data->inv->slots[i].selected = sfTrue;
        sfRectangleShape_setOutlineThickness(data->inv->slots[i].slot, 1.5);
    } else {
        sfRectangleShape_setOutlineThickness(data->inv->slots[i].slot, 1);
    }
    sfRenderWindow_drawRectangleShape(data->window,
        data->inv->slots[i].slot, NULL);
    if (data->inv->slots[i].item_id != 0 &&
        data->inv->slots[i].selected != sfTrue)
        display_items(data, sprite_pos, data->inv->slots[i].item_id);
    conditions_check_2(data, i);
}

void display_slots(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - 210, center.y + 30};
    int status = 0;

    for (int i = 0; i < 48; i++) {
        sprite_pos.x += 30;
        if (sprite_pos.x >= center.x + 180) {
            sprite_pos.x = center.x - 180;
            sprite_pos.y += 30;
        }
        if (i >= 36 && status != 1) {
            status = 1;
            sprite_pos.y += 15;
        }
        sfRectangleShape_setPosition(data->inv->slots[i].slot, sprite_pos);
        conditions_check_1(data, i, sprite_pos);
        data->selected_id = 0;
    }
}
