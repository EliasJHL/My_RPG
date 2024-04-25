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
#define UP_KEY(e) (sfKeyboard_isKeyPressed(sfKeyZ))
#define UP(e) (sfKeyboard_isKeyPressed(sfKeyUp) || UP_KEY(e))
#define DOWN_KEY(e) (sfKeyboard_isKeyPressed(sfKeyS))
#define DOWN(e) (sfKeyboard_isKeyPressed(sfKeyDown) || DOWN_KEY(e))
#define RIGHT_KEY(e) (sfKeyboard_isKeyPressed(sfKeyD))
#define RIGHT(e) (sfKeyboard_isKeyPressed(sfKeyRight) || RIGHT_KEY(e))
#define LEFT_KEY(e) (sfKeyboard_isKeyPressed(sfKeyQ))
#define LEFT(e) (sfKeyboard_isKeyPressed(sfKeyLeft) || LEFT_KEY(e))
#define SPACE(e) (sfKeyboard_isKeyPressed(sfKeySpace))

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

// Life data stock
typedef struct life_s {
    sfSprite *heart;
    sfVector2f heart_pos;
    struct life_s *next;
}life_t;

// Player data | animation = 1 → animation en cours | 0 → idle
typedef struct player_s {
    int animation;
    int direction;
    int life;
    int xp;
    int level;
    float zoom;
    sfClock *clock;
    sfTime elapsed_time;
    sfSprite *player_sprite;
    sfVector2f player_pos;
    sfIntRect rect;
    sfView *camera;
    life_t *life_hud;
} player_t;

// Map struct
typedef struct map_s {
    sfSprite *map_sprite;
    sfVector2f map_pos;
} map_t;

// HUD struct | 0 : Day | 1 : Night | 2 : Rain
typedef struct hud_s {
    int meteo_status;
    sfClock *clock_meteo;
    sfTime time_meteo;
    sfSprite *meteo;
    sfSprite *hud_holder;
    sfVector2f hud_pos;
    sfVector2f meteo_pos;
} hud_t;

//1 : Menu | 2 : Options | 3 : Pause | 4 : Inventory | 5 : Quests | 6 : Stats
typedef struct data_s {
    int hud_state;
    sfRenderWindow *window;
    map_t *map;
    player_t *player;
    menu_t *menu;
    pause_t *pause;
    hud_t *hud;
}data_t;

// Init structs & data
map_t *init_map(void);
player_t *init_player(void);
menu_t *init_menu(void);
pause_t *init_pause(void);
hud_t *hud_init(void);
void init_life(data_t *data);
void start_meteo(data_t *data);

//animations functions
void move(data_t *data, int top);
void idle(data_t *data, int top);
void attack(data_t *data);

// HUD Display
void pause_menu(data_t *data);
void inventory_menu(data_t *data);
void hud_player(data_t *data);
void meteo_display(data_t *data);
void background(data_t *data);

// Basic Functions
int player_basics(sfEvent event, data_t *data);

//event function (player movements)
void player_movement(sfEvent event, data_t *data, sfVector2f *pos);
