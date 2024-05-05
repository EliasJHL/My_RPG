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
    sfVector2f selected;

    while (item != NULL) {
        if (item->item_id == data->inv->slots[i].item_id && j == 1) {
            pos = (sfVector2f){pos.x - 1, pos.y - 2};
            sfSprite_setPosition(item->item, pos);
            selected = (sfVector2f){sfSprite_getScale(item->item).x * 1.1,
                sfSprite_getScale(item->item).y * 1.1};
            sfSprite_setScale(item->item, selected);
            sfRenderWindow_drawSprite(data->window, item->item, NULL);
            sfSprite_setScale(item->item, item->original_scale);
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
    data->player->item_selected = data->inv->slots[i].item_id;
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

static void display_life(data_t *data, sfVector2f center)
{
    sfVector2f sprite_pos;
    int life = 0;

    sprite_pos = (sfVector2f){center.x - 390, center.y - 200};
    data->player->life_hud->rect.left -= 48;
    while (life < data->player->life) {
        data->player->life_hud->rect.left -= 48;
        life += 34;
    }
    if (data->player->life_hud->rect.left > 288)
        data->player->life_hud->rect.left = 288;
    sfSprite_setTextureRect(data->player->life_hud->heart,
        data->player->life_hud->rect);
    sfSprite_setScale(data->player->life_hud->heart, (sfVector2f){1.8, 1.8});
    sfSprite_setPosition(data->player->life_hud->heart, sprite_pos);
    sfRenderWindow_drawSprite(data->window,
        data->player->life_hud->heart, NULL);
}

void display_life_hud(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);

    data->player->life_hud->rect.top = 0;
    data->player->life_hud->rect.left = 384;
    data->player->life_hud->rect.width = 48;
    data->player->life_hud->rect.height = 16;
    display_life(data, center);
}
