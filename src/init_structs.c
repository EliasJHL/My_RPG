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
    sfTexture *txt = sfTexture_createFromFile("assets/Map.png", NULL);

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
    player->clock = sfClock_create();
    sfSprite_setScale(player->player_sprite, (sfVector2f){1, 1});
    sfSprite_setTexture(player->player_sprite, txt, sfTrue);
    sfSprite_setTextureRect(player->player_sprite, (sfIntRect){0, 0, 64, 64});
    player->player_pos.x = 1280;
    player->player_pos.y = 720;
    sfSprite_setPosition(player->player_sprite, player->player_pos);
    player->camera = sfView_create();
    sfView_setCenter(player->camera, player->player_pos);
    sfView_setSize(player->camera, (sfVector2f){1920, 1080});
    sfView_zoom(player->camera, 1);
    free(txt);
    return player;
}

pause_t *init_pause(void)
{
    pause_t *pause = malloc(sizeof(pause_t));
    sfTexture *bg = sfTexture_createFromFile("assets/bg_pause.png", NULL);

    pause->bg_pause = sfSprite_create();
    sfSprite_setTexture(pause->bg_pause, bg, sfTrue);
    pause->bg_pos.x = (1920 / 2) - (416 / 2);
    pause->bg_pos.y = (1080 / 2) - (448 / 2);
    sfSprite_setPosition(pause->bg_pause, pause->bg_pos);
    free(bg);
    return pause;
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f pos = {0, 0};

    sfRectangleShape_setSize(shape, (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(shape, (sfColor){0, 0, 0, 150});
    sfRectangleShape_setPosition(shape, pos);
    menu->shape = shape;
    menu->menu_pos = pos;
    return menu;
}

hud_t *hud_init(void)
{
    hud_t *hud = malloc(sizeof(hud_t));
    sfTexture *hud_holder = sfTexture_createFromFile("assets/player_info.png",
        NULL);

    hud->meteo_status = 3;
    hud->hud_holder = sfSprite_create();
    sfSprite_setTexture(hud->hud_holder, hud_holder, sfTrue);
    hud->hud_pos.x = 100;
    hud->hud_pos.y = 50;
    sfSprite_setPosition(hud->hud_holder, hud->hud_pos);
    hud->clock_meteo = sfClock_create();
    free(hud_holder);
    return hud;
}
