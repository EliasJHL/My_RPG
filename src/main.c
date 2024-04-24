/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void display_hud(sfEvent event, data_t *data)
{
    if (event.key.code == sfKeyEscape)
        data->hud_state = 3;
    if (event.key.code == sfKeyE)
        data->hud_state = 4;
    if (event.key.code == sfKeyB)
        data->hud_state = 5;
    if (event.key.code == sfKeyN)
        data->hud_state = 6;
}

// Temporary function
static void meteo_changer(sfEvent event, data_t *data)
{
    if (event.key.code == sfKeyNum1)
        data->hud->meteo_status = 1;
    if (event.key.code == sfKeyNum2)
        data->hud->meteo_status = 2;
    if (event.key.code == sfKeyNum3)
        data->hud->meteo_status = 3;
}

static void disable_hud(sfEvent event, data_t *data)
{
    if (event.key.code == sfKeyEscape && data->hud_state == 3)
        data->hud_state = 0;
    if (event.key.code == sfKeyE && data->hud_state == 4)
        data->hud_state = 0;
    if (event.key.code == sfKeyB && data->hud_state == 5)
        data->hud_state = 0;
    if (event.key.code == sfKeyN && data->hud_state == 6)
        data->hud_state = 0;
}

void event_handler(sfRenderWindow *window, sfEvent event, data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->player->player_sprite);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (data->hud_state == 0)
            display_hud(event, data);
        else
            disable_hud(event, data);
        meteo_changer(event, data);
    }
    if (data->hud_state == 0) {
        player_movement(event, data, &pos);
        sfSprite_setPosition(data->player->player_sprite, pos);
    }
}

static void camera_handler(data_t *data)
{
    sfVector2f pos = sfSprite_getPosition(data->player->player_sprite);

    pos.x += (64 * 3) / 2;
    pos.y += (64 * 3) / 2;
    sfView_setCenter(data->player->camera, pos);
    sfRenderWindow_setView(data->window, data->player->camera);
}

void draw_sprites(sfRenderWindow *window, data_t *data)
{
    sfRenderWindow_drawSprite(window, data->map->map_sprite, NULL);
    sfRenderWindow_drawSprite(window, data->player->player_sprite, NULL);
    hud_player(data);
    meteo_display(data);
}

void game_loop(data_t *data)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;

    data->window = sfRenderWindow_create(mode, "My_RPG", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(data->window, 60);
    while (sfRenderWindow_isOpen(data->window)) {
        while (sfRenderWindow_pollEvent(data->window, &event))
            event_handler(data->window, event, data);
        sfRenderWindow_clear(data->window, sfBlack);
        draw_sprites(data->window, data);
        player_basics(event, data);
        camera_handler(data);
        sfRenderWindow_display(data->window);
    }
}

int main(void)
{
    data_t *data = malloc(sizeof(data_t));

    data->hud_state = 0;
    data->map = init_map();
    data->player = init_player();
    data->menu = init_menu();
    data->pause = init_pause();
    data->hud = hud_init();
    game_loop(data);
    free(data->map);
    free(data);
    return 0;
}
