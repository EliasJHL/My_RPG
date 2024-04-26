/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

int is_clicked(data_t *data, sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(data->window);

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        return 1;
    }
    return 0;
}

static void pos_menu(data_t *data)
{
    sfVector2f view_center = sfView_getCenter(data->player->camera);
    sfVector2f pos = {view_center.x - 416 / 2 + 60, view_center.y - 448 / 2};

    pos.y += 70;
    sfSprite_setPosition(data->pause->resume, pos);
    pos.y += 80;
    sfSprite_setPosition(data->pause->options, pos);
    pos.y += 80;
    sfSprite_setPosition(data->pause->menu, pos);
    pos.y += 80;
    sfSprite_setPosition(data->pause->exit, pos);
    sfSprite_setScale(data->pause->resume, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(data->pause->exit, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(data->pause->menu, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(data->pause->options, (sfVector2f){0.5, 0.5});
}

static void pause_menu_sprites(data_t *data)
{
    pos_menu(data);
    sfRenderWindow_drawSprite(data->window, data->pause->bg_pause, NULL);
    sfRenderWindow_drawSprite(data->window, data->pause->resume, NULL);
    sfRenderWindow_drawSprite(data->window, data->pause->exit, NULL);
    sfRenderWindow_drawSprite(data->window, data->pause->menu, NULL);
}

void pause_menu(data_t *data)
{
    sfVector2f view_center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {view_center.x - 416 / 2, view_center.y - 448 / 2};

    sfSprite_setPosition(data->pause->bg_pause, sprite_pos);
    pause_menu_sprites(data);
    sfRenderWindow_drawSprite(data->window, data->pause->options, NULL);
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
    int x = 420;
    int y = 190;
    int pos_x = 0;
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos;
    life_t *current = data->player->life_hud;

    for (int i = 0; i < 10; i++) {
        sprite_pos = (sfVector2f){(center.x - x) + pos_x, center.y - y};
        sfSprite_setPosition(current->heart, sprite_pos);
        sfRenderWindow_drawSprite(data->window, current->heart, NULL);
        current = current->next;
        pos_x += 10;
    }
}

// A REFAIRE POUR NE PAS HARDCODE LES POSITIONS
void hud_player(data_t *data)
{
    int x = 470;
    int y = 270;
    float zoom = data->player->zoom + 0.3;
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - x, center.y - y};

    sfSprite_setScale(data->hud->hud_holder, (sfVector2f){zoom, zoom});
    sfSprite_setPosition(data->hud->hud_holder, sprite_pos);
    sfRenderWindow_drawSprite(data->window, data->hud->hud_holder, NULL);
    display_life(data);
}
