/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void destroy_clock(data_t *data)
{
    sfTexture *txt = sfTexture_createFromFile("assets/player/p.png", NULL);

    sfClock_destroy(data->player->clock);
    sfClock_destroy(data->hud->clock_meteo);
    sfTexture_destroy(txt);
}

void destroy_sprite(data_t *data)
{
    sfSprite_destroy(data->player->player_sprite);
    sfSprite_destroy(data->hud->hud_holder);
    sfSprite_destroy(data->hud->item_hold);
    sfSprite_destroy(data->pause->menu);
    sfSprite_destroy(data->pause->resume);
    sfSprite_destroy(data->pause->exit);
    sfSprite_destroy(data->pause->options);
    sfSprite_destroy(data->pause->bg_pause);
    sfSprite_destroy(data->notif->notif_content);
    sfSprite_destroy(data->notif->notif);
}

void close_the_game(data_t *data)
{
    destroy_clock(data);
    destroy_sprite(data);
    free(data->player);
    free(data->hud);
    free(data->pause);
    free(data->notif);
    free(data->items);
    free(data->map);
    free(data->inv);
    sfRenderWindow_destroy(data->window);
    free(data);
}
