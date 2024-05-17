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
#define MOVE(e) (UP(e) || DOWN(e) || LEFT(e) || RIGHT(e))
#define CHECK_X_NPC(pos, npc, n) (pos.x >= npc.x - n && pos.x <= npc.x + n)
#define CHECK_Y_NPC(pos, npc, n) (pos.y >= npc.y - n && pos.y <= npc.y + n)
#define CHECK_NPC(p, n, nb) (CHECK_X_NPC(p, n, nb) && CHECK_Y_NPC(p, n, nb))
#define TILE 16
#define MAP_SIZE_X 3200
#define MAP_SIZE_Y 3200

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
    sfBool selected;
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
    sfBool selected;
    int item_id;
    int slot_id;
} slots_t;

typedef struct inventory_s {
    bool status;
    sfSprite *item_selected;
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

typedef struct collision_s {
    sfRectangleShape *col_sprite;
    sfVector2f col_pos;
    int collision;
} collision_t;

// Player data | animation = 1 → animation en cours | 0 → idle
typedef struct player_s {
    int item_selected;
    int animation;
    int direction;
    int life;
    int hungry;
    int xp;
    int level;
    float zoom;
    bool is_talking;
    sfClock *clock;
    sfTime elapsed_time;
    sfSprite *player_sprite;
    sfVector2f player_pos;
    sfVector2f spawn_point;
    sfIntRect rect;
    sfView *camera;
    life_t *life_hud;
} player_t;

typedef struct boss_s {
    int anim;
    int health;
    sfClock *clockb;
    sfTime elapsed_timeb;
    sfSprite *boss_sprite;
    sfVector2f boss_pos;
    sfIntRect rectb;
} boss_t;

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
    bool legendary;
    bool active;
    char *content;
    sfSprite *victory_effect;
    sfVector2f vic_pos;
    sfClock *clock;
    sfTime elapsed_time;
    sfSprite *notif;
    sfText *text;
    sfVector2f notif_pos;
    sfVector2f text_pos;
}notif_t;

typedef struct tuto_s {
    sfClock *clock;
    sfSprite *tuto;
    sfSprite *tuto_finsished;
    sfSprite *finsish_effect;
    bool move;
    bool attack;
    bool inventory;
}tuto_t;

// NPC sprite → name.png | talk sprite → name_talk.png
typedef struct npc_s {
    char *npc_name;
    bool active;
    bool to_talk;
    bool is_tuto;
    bool is_sign;
    char *txt_sign;
    sfSprite *sprite;
    sfSprite *talk_sprite;
    sfClock *clock;
    sfTime elapsed_time;
    sfVector2f pos;
    sfIntRect rect;
    int nb_frames;
    struct npc_s *next;
}npc_t;

typedef struct text_hud_s {
    sfText *talk;
    sfText *open_chest;
}text_t;

typedef struct bubble_text_s {
    bool writing;
    sfClock *clock;
    sfTime elapsed_time;
    sfText *name;
    sfText *text;
    sfRectangleShape *bubble;
    sfVector2f name_pos;
    sfVector2f bubble_pos;
    sfVector2f text_pos;
}bubble_text_t;

//1 : Menu | 2 : Options | 3 : Pause | 4 : Inventory | 5 : Quests | 6 : Stats
// Mode tuto → First Game → Save not loaded
typedef struct data_s {
    int hud_state;
    int *map_data;
    bool tuto_mode;
    int selected_id;
    sfEvent event;
    sfRenderWindow *window;
    map_t *map;
    player_t *player;
    menu_t *menu;
    pause_t *pause;
    hud_t *hud;
    inventory_t *inv;
    items_t *items;
    notif_t *notif;
    tuto_t *tuto;
    collision_t *collision;
    npc_t *npc;
    text_t *text;
    bubble_text_t *bubble_text;
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
tuto_t *init_tuto(void);
collision_t *init_collision(void);
void init_text(data_t *data);
void init_bubble_text(data_t *data);

// UI functions
int is_clicked(data_t *data, sfSprite *sprite);
int is_clicked_slot(data_t *data, sfRectangleShape *slot);
int is_hover(data_t *data, sfSprite *sprite);
void action_menu(sfEvent event, data_t *data);
void display_item_holder(data_t *data);
void draw_sprites(sfRenderWindow *window, data_t *data);
void camera_handler(data_t *data);
void event_handler(sfRenderWindow *window, sfEvent event, data_t *data);

//attack functions
void reset_hit(data_t *data);
void hit_right_player(data_t *data);
void hit_up_player(data_t *data);

//game modes functions
void tutorial_game(data_t *data, sfEvent event);

//animations functions
void move(data_t *data, int top);
void idle(data_t *data, int top);
void attack(data_t *data);

// Inventory system functions
void item_hold_change(sfEvent event, data_t *data);
void display_slots(data_t *data);

//NPC System
void init_npc(data_t *data);
void display_npc(data_t *data);
void detect_npc(data_t *data);

// Map functions
int **init_map_collision(void);

// HUD Display
void pause_menu(data_t *data);
void inventory_menu(data_t *data);
void hud_player(data_t *data);
void meteo_display(data_t *data);
void background(data_t *data);

//notification system
void notification(data_t *data, char *content, int legendary);
void notification_display(data_t *data);

// Basic Functions for player
int player_basics(sfEvent event, data_t *data);

//event function (player movements)
void player_movement(data_t *data);
void move_player(data_t *data);

// Values handler & call functions
int dead_condition(data_t *data);
void xp_add(int xp, data_t *data);
void starve(int food, data_t *data);
void eat(int food, data_t *data);
void damage(int life, data_t *data);
void heal(int life, data_t *data);

//Collision Functions
collision_t *get_rectangle_above_player(data_t *data);
collision_t *get_rectangle_under_player(data_t *data);
collision_t *get_rectangle_left_player(data_t *data);
collision_t *get_rectangle_right_player(data_t *data);
int collision_check_up(data_t *data);
int collision_check_down(data_t *data);
int collision_check_left(data_t *data);
int collision_check_right(data_t *data);

//destroy game (free memory)
void close_the_game(data_t *data);

//Temporary function (To be removed)
void debug_life(data_t *data);
void debug_hitbox_collision(data_t *data);
