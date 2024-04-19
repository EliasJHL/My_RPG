/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct player_s {
    sfSprite *player_sprite;
    sfVector2f player_pos;
    sfIntRect player_rect;
    sfView *camera;
} player_t;

typedef struct map_s {
    sfSprite *map_sprite;
    sfVector2f map_pos;
} map_t;

typedef struct data_s {
    map_t *map;
    player_t *player;
}data_t;

map_t *init_map(void);
player_t *init_player(void);
