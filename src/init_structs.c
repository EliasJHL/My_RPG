/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));
    sfTexture *txt = sfTexture_createFromFile("assets/map.jpg", NULL);

    map->map_sprite = sfSprite_create();
    sfSprite_setTexture(map->map_sprite, txt, sfTrue);
    map->map_pos.x = 0;
    map->map_pos.y = 0;
    free(txt);
    return map;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfTexture *txt = sfTexture_createFromFile("assets/player.png", NULL);

    player->player_sprite = sfSprite_create();
    sfSprite_setTexture(player->player_sprite, txt, sfTrue);
    player->player_pos.x = 0;
    player->player_pos.y = 0;
    player->player_rect.top = 0;
    player->player_rect.left = 0;
    player->player_rect.width = 32;
    player->player_rect.height = 32;
    player->camera = sfView_create();
    sfView_setCenter(player->camera, player->player_pos);
    free(txt);
    return player;
}
