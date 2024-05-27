/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void type_hud(data_t *data)
{
    if (data->notif->active == true)
        notification_display(data);
    if (data->hud_state == 3)
        pause_menu(data);
    if (data->hud_state == 4)
        inventory_menu(data);
}

void idle(data_t *data, int top)
{
    double seconds;

    data->player->elapsed_time = sfClock_getElapsedTime(data->player->clock);
    seconds = sfTime_asSeconds(data->player->elapsed_time);
    if (seconds >= 0.15) {
        data->player->rect.top = top;
        data->player->rect.left += 48;
        data->player->rect.height = 48;
        data->player->rect.width = 48;
        if (data->player->rect.left >= data->player->rect.width * 6)
            data->player->rect.left = 0;
        sfClock_restart(data->player->clock);
        sfSprite_setTextureRect(data->player->player_sprite,
                                data->player->rect);
    }
}

static void item_hold_change_2(sfEvent event, data_t *data)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum6))
        data->hud->item_slot_nb = 5;
    if (sfKeyboard_isKeyPressed(sfKeyNum7))
        data->hud->item_slot_nb = 6;
    if (event.text.unicode == '"')
        data->hud->item_slot_nb = 7;
    if (sfKeyboard_isKeyPressed(sfKeyNum9))
        data->hud->item_slot_nb = 8;
    if (sfKeyboard_isKeyPressed(sfKeyNum0))
        data->hud->item_slot_nb = 9;
    if (sfKeyboard_isKeyPressed(sfKeyEqual))
        data->hud->item_slot_nb = 11;
}

void item_hold_change(sfEvent event, data_t *data)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1))
        data->hud->item_slot_nb = 0;
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
        data->hud->item_slot_nb = 1;
    if (sfKeyboard_isKeyPressed(sfKeyNum3))
        data->hud->item_slot_nb = 2;
    if (sfKeyboard_isKeyPressed(sfKeyNum4))
        data->hud->item_slot_nb = 3;
    if (sfKeyboard_isKeyPressed(sfKeyNum5))
        data->hud->item_slot_nb = 4;
    if (event.text.unicode == '8')
        data->hud->item_slot_nb = 10;
    item_hold_change_2(event, data);
}

items_t *get_item_by_id(data_t *data, int id)
{
    items_t *items = data->items;

    while (items != NULL) {
        if (items->item_id == id) {
            return items;
        }
        items = items->next;
    }
    return NULL;
}

static void check_use_item(data_t *data)
{
    items_t *item = NULL;

    if (sfMouse_isButtonPressed(sfMouseLeft) && data->hud_state == 0) {
        item = get_item_by_id(data, data->hud->item_slot_nb);
        if (item == NULL)
            return;
        if (strcmp(item->item_type, "health")) {
            heal(item->item_value, data);
        }
        if (strcmp(item->item_type, "food")) {
            heal(item->item_value, data);
        }
    }
}

void player_movement(data_t *data)
{
    if (data->player->is_attacking && data->hud_state == 0
        || SPACE(event) && data->hud_state == 0) {
        data->player->is_attacking = true;
        data->player->animation = 1;
        attack(data);
    } else if (!data->player->is_attacking && MOVE(event)
        && data->hud_state == 0) {
        data->player->animation = 1;
        move_player(data);
    }
}

int player_basics(sfEvent event, data_t *data)
{
    type_hud(data);
    detect_npc(data);
    check_use_item(data);
    if (data->player->life > 200)
        data->player->life = 200;
    if (data->player->life < 0)
        data->player->life = 0;
    return 0;
}
