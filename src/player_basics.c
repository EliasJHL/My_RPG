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

static void move_player_2(data_t *data, sfVector2f *pos)
{
    if (LEFT(event)) {
        move(data, 192);
        pos->x -= 3;
        sfSprite_setScale(data->player->player_sprite, (sfVector2f){-1, 1});
        data->player->direction = 2;
    }
    if (RIGHT(event)) {
        move(data, 192);
        pos->x += 3;
        sfSprite_setScale(data->player->player_sprite, (sfVector2f){1, 1});
        data->player->direction = 3;
    }
}

void move_player(data_t *data, sfVector2f *pos)
{
    if (UP(event) || DOWN(event) || LEFT(event) || RIGHT(event))
        data->player->animation = 1;
    if (UP(event)) {
        move(data, 240);
        pos->y -= 3;
        sfSprite_setScale(data->player->player_sprite, (sfVector2f){1, 1});
        data->player->direction = 0;
    }
    if (DOWN(event)) {
        move(data, 144);
        pos->y += 3;
        sfSprite_setScale(data->player->player_sprite, (sfVector2f){1, 1});
        data->player->direction = 1;
    }
    move_player_2(data, pos);
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

static void item_hold_change(sfEvent event, data_t *data)
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

void debug_life(data_t *data, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyP))
        data->player->life += 10;
    if (sfKeyboard_isKeyPressed(sfKeyM))
        data->player->life -= 10;
    if (sfKeyboard_isKeyPressed(sfKeyL))
        notification(data, 1);
}

void player_movement(sfEvent event, data_t *data, sfVector2f *pos)
{
    if (event.type == sfEvtKeyPressed) {
        data->player->animation = 1;
        move_player(data, pos);
        if (!UP(event) && !DOWN(event) && !LEFT(event) && !RIGHT(event))
            data->player->animation = 0;
        if (SPACE(event)){
            data->player->animation = 1;
            attack(data);
        }
        item_hold_change(event, data);
        debug_life(data, event);
    }
    if (event.type == sfEvtKeyReleased) {
        if (UP(event) || DOWN(event) || LEFT(event) || RIGHT(event))
            data->player->animation = 0;
        if (SPACE(event))
            data->player->animation = 0;
    }
}

int player_basics(sfEvent event, data_t *data)
{
    type_hud(data);
    if (data->player->life > 200)
        data->player->life = 200;
    if (data->player->life < 0)
        data->player->life = 0;
    return 0;
}
