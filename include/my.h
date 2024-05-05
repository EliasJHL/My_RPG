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
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
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
    sfSprite *menu;
    sfVector2f bg_pos;
    sfVector2f resume_pos;
    sfVector2f options_pos;
    sfVector2f exit_pos;
} pause_t;

// Items stock data
typedef struct items_s {
    sfVector2f original_scale;
    sfVector2f item_pos;
    sfBool in_inventory;
    sfBool is_picked;
    sfSprite *item;
    char *item_name;
    char *item_type;
    int item_amount;
    int item_max_amount;
    int item_value;
    int item_id;
    int price;
    struct items_s *next;
} items_t;

// Inventory struct
typedef struct slots_s {
    sfRectangleShape *slot;
    sfVector2f slot_pos;
    int item_id;
    int slot_id;
} slots_t;

typedef struct inventory_s {
    sfRectangleShape *inv;
    sfSprite *inv_sprite;
    sfVector2f inv_pos;
    sfVector2f sprite_pos;
    slots_t *slots;
} inventory_t;

// Life data stock
typedef struct life_s {
    sfSprite *heart;
    sfVector2f heart_pos;
    sfIntRect rect;
}life_t;

// Player data | animation = 1 → animation en cours | 0 → idle
typedef struct player_s {
    int item_selected;
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
    int item_slot_nb;
    sfClock *clock_meteo;
    sfTime time_meteo;
    sfSprite *meteo;
    sfSprite *hud_holder;
    sfSprite *item_hold;
    sfVector2f hud_pos;
    sfVector2f meteo_pos;
    sfVector2f item_hold_pos;
} hud_t;

// notification system
typedef struct notif_s {
    bool active;
    int content;
    sfClock *clock;
    sfTime elapsed_time;
    sfSprite *notif_content;
    sfSprite *notif;
    sfVector2f notif_pos;
    sfVector2f text_pos;
}notif_t;

//1 : Menu | 2 : Options | 3 : Pause | 4 : Inventory | 5 : Quests | 6 : Stats
typedef struct data_s {
    int hud_state;
    sfRenderWindow *window;
    map_t *map;
    player_t *player;
    menu_t *menu;
    pause_t *pause;
    hud_t *hud;
    inventory_t *inv;
    items_t *items;
    notif_t *notif;
}data_t;

// Init structs & data
map_t *init_map(void);
player_t *init_player(void);
menu_t *init_menu(void);
pause_t *init_pause(void);
hud_t *hud_init(void);
void init_life(data_t *data);
void start_meteo(data_t *data);
inventory_t *init_inventory(void);
int init_items(data_t *data);
void display_life_hud(data_t *data);
void init_notification_sprite(data_t *data);

// UI functions
int is_clicked(data_t *data, sfSprite *sprite);
void action_menu(sfEvent event, data_t *data);
void display_item_holder(data_t *data);

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

//notification system
void notification(data_t *data, int nb);
void notification_display(data_t *data);

// Basic Functions
int player_basics(sfEvent event, data_t *data);

//event function (player movements)
void player_movement(sfEvent event, data_t *data, sfVector2f *pos);
