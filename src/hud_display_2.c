/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void item_display_holder(data_t *data, int i, sfVector2f pos, int j)
{
    items_t *item = data->items;

    while (item != NULL) {
        if (item->item_id == data->inv->slots[i].item_id && j == 1) {
            sfSprite_setPosition(item->item, pos);
            sfRenderWindow_drawSprite(data->window, item->item, NULL);
        }
        if (item->item_id == data->inv->slots[i].item_id && j == 0) {
            sfSprite_setPosition(item->item, pos);
            sfRenderWindow_drawSprite(data->window, item->item, NULL);
        }
        item = item->next;
    }
}

static void display_item_2(data_t *data, int i, sfVector2f slot, sfVector2f s)
{
    sfRectangleShape_setScale(data->inv->slots[i].slot, s);
    slot.x -= 1;
    slot.y -= 2;
    sfRectangleShape_setPosition(data->inv->slots[i].slot, slot);
    slot.x += 1;
    slot.y += 2;
    sfRenderWindow_drawRectangleShape(data->window,
        data->inv->slots[i].slot, NULL);
    item_display_holder(data, i, slot, 1);
}

static void display_item_holder_slots(data_t *data, sfVector2f center)
{
    sfVector2f slots = {center.x - 180, center.y + 199};
    sfVector2f selected = {1.1, 1.1};
    sfVector2f normal = {1, 1};

    for (int i = 36; i < 48; i++) {
        if (i == data->hud->item_slot_nb + 36) {
            display_item_2(data, i, slots, selected);
        } else {
            sfRectangleShape_setPosition(data->inv->slots[i].slot, slots);
            sfRenderWindow_drawRectangleShape(data->window,
                data->inv->slots[i].slot, NULL);
            item_display_holder(data, i, slots, 0);
        }
        slots.x += 30;
        sfRectangleShape_setScale(data->inv->slots[i].slot, normal);
    }
}

void display_item_holder(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - 210, center.y + 160};

    sfSprite_setPosition(data->hud->item_hold, sprite_pos);
    sfRenderWindow_drawSprite(data->window, data->hud->item_hold, NULL);
    display_item_holder_slots(data, center);
}
