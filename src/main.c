/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void event_handler(sfRenderWindow *window, sfEvent event, data_t *data)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeyZ)
            sfSprite_move(data->player->player_sprite, (sfVector2f){0, -5});
        if (event.key.code == sfKeyS)
            sfSprite_move(data->player->player_sprite, (sfVector2f){0, 5});
        if (event.key.code == sfKeyQ)
            sfSprite_move(data->player->player_sprite, (sfVector2f){-5, 0});
        if (event.key.code == sfKeyD)
            sfSprite_move(data->player->player_sprite, (sfVector2f){5, 0});
    }
}

void draw_sprites(sfRenderWindow *window, data_t *data)
{
    sfRenderWindow_drawSprite(window, data->map->map_sprite, NULL);
    sfRenderWindow_drawSprite(window, data->player->player_sprite, NULL);
}

void game_loop(data_t *data)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "My_RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            event_handler(window, event, data);
        sfRenderWindow_clear(window, sfBlack);
        draw_sprites(window, data);
        sfRenderWindow_display(window);
    }
}

int main(void)
{
    data_t *data = malloc(sizeof(data_t));

    data->map = init_map();
    data->player = init_player();
    game_loop(data);
    free(data->map);
    free(data);
    return 0;
}
