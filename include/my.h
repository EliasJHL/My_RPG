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
#define UP(e) (e.key.code == sfKeyZ || e.key.code == sfKeyUp)
#define DOWN(e) (e.key.code == sfKeyS || e.key.code == sfKeyDown)
#define RIGHT(e) (e.key.code == sfKeyD || e.key.code == sfKeyRight)
#define LEFT(e) (e.key.code == sfKeyQ || e.key.code == sfKeyLeft)

// Menu struct
typedef struct menu_s {
    sfRectangleShape *shape;
    sfVector2f menu_pos;
} menu_t;

// Pause menu struct
typedef struct pause_s {
    sfSprite *bg_pause;
    sfSprite *resume;
    sfSprite *options;
    sfSprite *exit;
    sfVector2f bg_pos;
    sfVector2f resume_pos;
    sfVector2f options_pos;
    sfVector2f exit_pos;
} pause_t;

// Items stock data
typedef struct items_s {
    sfRectangleShape *slot;
    sfVector2f slot_pos;
    sfSprite *item;
    sfVector2f item_pos;
    int item_id;
    int item_amount;
    struct items_s *next;
} items_t;

// Inventory struct
typedef struct slots_s {
    sfRectangleShape *slot;
    sfVector2f slot_pos;
    items_t *items;
    struct slots_s *next;
} slots_t;

typedef struct inventory_s {
    sfRectangleShape *inv;
    sfVector2f inv_pos;
    slots_t *slots;
} inventory_t;

// Player data
typedef struct player_s {
    sfSprite *player_sprite;
    sfVector2f player_pos;
    sfIntRect rect;
    sfView *camera;
} player_t;

// Map struct
typedef struct map_s {
    sfSprite *map_sprite;
    sfVector2f map_pos;
} map_t;

//1 : Menu | 2 : Options | 3 : Pause | 4 : Inventory | 5 : Quests | 6 : Stats
typedef struct data_s {
    int hud_state;
    sfClock *clock;
    sfTime elapsed_time;
    sfRenderWindow *window;
    map_t *map;
    player_t *player;
    menu_t *menu;
    pause_t *pause;
}data_t;

// Init structs & data
map_t *init_map(void);
player_t *init_player(void);
menu_t *init_menu(void);
pause_t *init_pause(void);

//animations functions
void move(data_t *data, int top);

// HUD Display
void pause_menu(data_t *data);
void inventory_menu(data_t *data);

// Basic Functions
int player_basics(sfEvent event, data_t *data);

//event function (player movements)
void player_movement(sfEvent event, data_t *data, sfVector2f *pos);
