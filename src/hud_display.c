/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void pause_menu(data_t *data)
{
    sfVector2f view_center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {view_center.x - 416 / 2, view_center.y - 448 / 2};

    sfSprite_setPosition(data->pause->bg_pause, sprite_pos);
    sfRenderWindow_drawSprite(data->window, data->pause->bg_pause, NULL);
}

void inventory_menu(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - 1920 / 2, center.y - 1080 / 2};

    sfRectangleShape_setPosition(data->menu->shape, sprite_pos);
    sfRenderWindow_drawRectangleShape(data->window, data->menu->shape, NULL);
}

void display_life(data_t *data)
{
    int x = (1920 / 3) - 170;
    int y = (1080 / 3) + 20;
    int pos_x = 0;
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos;
    life_t *current = data->player->life_hud;

    for (int i = 0; i < 10; i++) {
        sprite_pos = (sfVector2f){(center.x - x) + pos_x, center.y - y};
        sfRenderWindow_drawSprite(data->window, current->heart, NULL);
        sfSprite_setPosition(current->heart, sprite_pos);
        current = current->next;
        pos_x += 18;
    }
}

void hud_player(data_t *data)
{
    int x = (1920 / 3) - 130;
    int y = (1080 / 2) - 65;
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - x, center.y - y};

    sfSprite_setPosition(data->hud->hud_holder, sprite_pos);
    sfRenderWindow_drawSprite(data->window, data->hud->hud_holder, NULL);
    display_life(data);
}
