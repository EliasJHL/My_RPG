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
#include <math.h>
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
#define GLOBAL sfRectangleShape_getGlobalBounds
#define TEXT_SLIME "assets/characters/slime.png"
#define TEXT_SKELETON "assets/characters/skeleton.png"
#define SLIME ennemies->slime[i]
#define SKELETON ennemies->skeleton[i]
#define SLIME_X data->ennemies->slime[i]->pos.x
#define SLIME_Y data->ennemies->slime[i]->pos.y
#define SKELETON_X data->ennemies->skeleton[i]->pos.x
#define SKELETON_Y data->ennemies->skeleton[i]->pos.y
#define PLAYER_X data->player->player_pos.x
#define PLAYER_Y data->player->player_pos.y
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
    sfText *life_text;
    sfSprite *heart;
    sfVector2f heart_pos;
    sfIntRect rect;
} life_t;

typedef struct collision_s {
    sfRectangleShape *hitbox;
    sfRectangleShape *col_sprite;
    sfVector2f col_pos;
    int collision;
} collision_t;

typedef struct quest_s {
    int id;
    int item_reward;
    int progression_count;
    int progression_goal;
    char *banner_name;
    char *title_full;
    char *description_full;
    char *title_short;
    char *description_short;
    bool is_active;
    bool has_progression;
    bool has_reward;
    bool is_finished;
    bool is_tutorial;
    struct quest_s *next;
}quest_t;

typedef struct quest_display_s {
    // Mini display
    sfText *title;
    sfText *description;
    sfText *progression;
    sfRectangleShape *mini_banner;
    sfRectangleShape *prog_bar;
    sfRectangleShape *prog_bar_bg;
    sfVector2f prog_bar_pos;
    sfVector2f mini_banner_pos;
    sfVector2f title_pos;
    sfVector2f description_pos;
    // Banner display
    sfText *title_full;
    sfText *description_full;
    sfRectangleShape *banner;
    sfVector2f banner_pos;
    sfVector2f title_full_pos;
    sfVector2f description_full_pos;
}quest_display_t;

// Player data | animation = 1 → animation en cours | 0 → idle
typedef struct player_s {
    int item_selected;
    int animation;
    int direction;
    int quest_id;
    int life;
    int hungry;
    int xp;
    int level;
    float zoom;
    bool doing_quest;
    bool is_talking;
    bool available;
    bool is_attacking;
    bool damage_taken;
    sfClock *clock;
    sfClock *clock2;
    sfTime elapsed_time;
    sfTime elapsed_time2;
    sfSprite *player_sprite;
    sfVector2f player_pos;
    sfVector2f spawn_point;
    sfIntRect rect;
    sfView *camera;
    life_t *life_hud;
    sfRectangleShape *hitbox;
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

typedef struct slime_s {
    int life;
    bool is_alive;
    bool is_mooving;
    sfClock *clock;
    sfTime elapsed_times;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfRectangleShape *hitbox;
} slime_t;

typedef struct skeleton_s {
    int life;
    int dir;
    int auto_time;
    bool is_alive;
    bool is_mooving;
    bool is_attacking;
    bool auto_mode;
    bool auto_mode_moov;
    sfClock *clock;
    sfClock *clock2;
    sfTime elapsed_times;
    sfTime elapsed_times2;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfRectangleShape *hitbox;
    sfRectangleShape *attack_hitbox;
} skeleton_t;

typedef struct ennemies_s {
    slime_t **slime;
    skeleton_t **skeleton;
    int slimex1;
    int slimex2;
    int slimey1;
    int slimey2;
    int skeletonx1;
    int skeletonx2;
    int skeletony1;
    int skeletony2;
} ennemies_t;

typedef struct map_s {
    sfSprite *map_sprite;
    sfSprite *map_top;
    sfVector2f map_top_pos;
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
    sfSprite *tuto_top;
    sfSprite *tuto_finsished;
    sfSprite *finsish_effect;
    bool move;
    bool attack;
    bool inventory;
}tuto_t;

typedef struct dialog_s {
    sfText *text;
    struct dialog_s *next;
}dialog_t;

typedef struct sprint_s {
    sfClock *clock;
    sfTime elapsed_time;
    float speed;
    int stamina;
    sfRectangleShape *stamina_rec;
    sfVector2f stamina_pos;
} sprint_t;

// NPC sprite → name.png | talk sprite → name_talk.png
typedef struct npc_s {
    char *npc_name;
    int dialog_count;
    int nb_dialog;
    char **dialog;
    bool talking;
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
} npc_t;

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

typedef struct drop_items_s {
    int id;
    bool is_recoverable;
    sfClock *clock;
    sfTime elapsed_time;
    sfVector2f pos;
    struct drop_items_s *next;
}drop_items_t;

//zoom_mode → 1 : zoom in | 0 : zoom out
typedef struct menu_window_s {
    sfRenderWindow *window;
    sfClock *clock;
    float zoom;
    bool zoom_mode;
    bool credits_mode;
    sfTime elapsed_time;
    sfEvent event;
    sfSprite *menu_bg;
    sfSprite *credits_hud;
    sfSprite *newgame;
    sfSprite *loadgame;
    sfSprite *credits;
    sfSprite *options;
    sfSprite *exit;
    sfSprite *newgame_hover;
    sfSprite *loadgame_hover;
    sfSprite *credits_hover;
    sfSprite *options_hover;
    sfSprite *exit_hover;
    sfSprite *cursor;
    sfSprite *cursor_hover;
    sfSprite *container;
    sfVector2f bg_pos;
    sfVector2f play_pos;
    sfVector2f options_pos;
    sfVector2f exit_pos;
}menu_window_t;

//1 : Menu | 2 : Options | 3 : Pause | 4 : Inventory | 5 : Quests | 6 : Stats
// Mode tuto → First Game → Save not loaded
typedef struct data_s {
    int count_dialog;
    int hud_state;
    int *map_data;
    bool tuto_mode;
    bool menu_mode;
    bool sign_display;
    bool dialog_finished;
    bool is_on_menu;
    int selected_id;
    sfMusic *menu_music;
    sfMusic *tutorial_music;
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
    collision_t *col_map;
    npc_t *npc;
    text_t *text;
    quest_t *quests;
    quest_display_t *quests_display;
    bubble_text_t *bubble_text;
    drop_items_t *drop_items;
    ennemies_t *ennemies;
    menu_window_t *menu_window;
    sprint_t *sprint;
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
collision_t *init_collision_map(void);
ennemies_t *init_ennemies(void);
void init_slime(ennemies_t *ennemies);
void init_skeleton(ennemies_t *ennemies);
menu_window_t *init_menu_window(void);
void init_mini_display(data_t *data);
void init_music(data_t *data);

//save system
void save_game(data_t *data, int slot);
void load_game(data_t *data, int slot);

// UI functions
int is_clicked(data_t *data, sfSprite *sprite);
int is_clicked_slot(data_t *data, sfRectangleShape *slot);
int is_hover(data_t *data, sfSprite *sprite);
void action_menu(sfEvent event, data_t *data);
void display_item_holder(data_t *data);
void draw_sprites(sfRenderWindow *window, data_t *data);
void camera_handler(data_t *data);
char *int_to_string(int nb);
void event_handler(sfRenderWindow *window, sfEvent event, data_t *data);

//menu functions
int menu(data_t *data);
void draw_btn(data_t *data);

//quest system
void display_mini_quest(data_t *data);

//attack functions
void reset_hit(data_t *data);
void hit_right_player(data_t *data);
void hit_up_player(data_t *data);
void hit_down_player(data_t *data);
void hit_left_player(data_t *data);
void timer_damage(data_t *data);

//ennemies functions
void spawn_slime(data_t *data);
void display_slime(data_t *data);
void move_slime(data_t *data);
void spawn_skeleton(data_t *data);
void display_skeleton(data_t *data);
void move_skeleton(data_t *data);
void choose_state(data_t *data, int i);
int collision_check_up_skeleton(data_t *data, skeleton_t *skeleton);
int collision_check_down_skeleton(data_t *data, skeleton_t *skeleton);
int collision_check_left_skeleton(data_t *data, skeleton_t *skeleton);
int collision_check_right_skeleton(data_t *data, skeleton_t *skeleton);
void auto_mode_skeleton(data_t *data, skeleton_t *skeleton);

//game modes functions
void tutorial_game(data_t *data, sfEvent event);

//animations functions
void move(data_t *data, int top);
void idle(data_t *data, int top);
void attack(data_t *data);

// Inventory system functions
void item_hold_change(sfEvent event, data_t *data);
void display_slots(data_t *data);
void drop_item(data_t *data, int id);
void display_drop_item(data_t *data);
void recover_item(data_t *data);

//NPC System
void init_npc(data_t *data);
void display_npc(data_t *data);
void detect_npc(data_t *data);
void config_dialog_npc(npc_t *node);
void npc_text(data_t *data, npc_t *npc, char *str);
void sign_text(data_t *data, npc_t *npc);
void text_writer(data_t *data, char *str, npc_t *npc);
void display_buuble(data_t *data, npc_t *npc);
void display_simple_text(data_t *data, npc_t *npc, char *str);

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
void init_sprint(data_t *data);
void sprint_check(data_t *data);

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
