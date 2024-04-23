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

typedef struct menu_s {
    sfRectangleShape *shape;
    sfVector2f menu_pos;
} menu_t;

typedef enum hud_s {
    NONE,
    MENU,
    OPTIONS,
    PAUSE,
    INVENTORY,
    QUESTS,
    STATS
} hud_t;

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

//1 : Menu | 2 : Options | 3 : Pause | 4 : Inventory | 5 : Quests | 6 : Stats
typedef struct data_s {
    int hud_state;
    sfRenderWindow *window;
    map_t *map;
    player_t *player;
    menu_t *menu;
}data_t;

// Init structs & data
map_t *init_map(void);
player_t *init_player(void);
menu_t *init_menu(void);

// HUD Display
void pause_menu(data_t *data);
void inventory_menu(data_t *data);

// Basic Functions
int player_basics(sfEvent event, data_t *data);

//event function (player movements)
void player_movement(sfEvent event, data_t *data);
