/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void init_life(data_t *data)
{
    sfTexture *heart;
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    data->player->life_hud = malloc(sizeof(life_t));
    data->player->life_hud->life_text = sfText_create();
    sfText_setFont(data->player->life_hud->life_text, font);
    sfText_setCharacterSize(data->player->life_hud->life_text, 50);
    sfText_setPosition(data->player->life_hud->life_text, (sfVector2f){0, 0});
    sfText_setColor(data->player->life_hud->life_text, sfBlack);
    sfText_setString(data->player->life_hud->life_text, "");
    sfText_setScale(data->player->life_hud->life_text,
        (sfVector2f){0.15, 0.15});
    heart = sfTexture_createFromFile("assets/slidebar.png", NULL);
    data->player->life_hud->heart = sfSprite_create();
    sfSprite_setTexture(data->player->life_hud->heart, heart, sfTrue);
    free(heart);
}

void start_meteo(data_t *data)
{
    int x = (1920 / 3) - 1050;
    int y = (1080 / 2) - 40;
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - x, center.y - y};
    sfTexture *t;

    t = sfTexture_createFromFile("assets/meteo_hud/day/1.png", NULL);
    data->hud->meteo = sfSprite_create();
    sfSprite_setTexture(data->hud->meteo, t, sfTrue);
    sfSprite_setPosition(data->hud->meteo, sprite_pos);
    sfSprite_setScale(data->hud->meteo, (sfVector2f){1, 1.5});
    free(t);
}

static void start_slots(inventory_t *inv)
{
    sfColor outline = sfColor_fromRGBA(180, 167, 148, 255);
    sfColor intern = sfColor_fromRGBA(216, 201, 172, 255);

    inv->slots = malloc(sizeof(slots_t) * 48);
    for (int i = 0; i < 48; i++) {
        inv->slots[i].item_id = 002;
        inv->slots[i].slot_id = i;
        inv->slots[i].slot = sfRectangleShape_create();
        inv->slots[i].slot_pos.x = 0;
        inv->slots[i].slot_pos.y = 0;
        sfRectangleShape_setOutlineThickness(inv->slots[i].slot, 1);
        sfRectangleShape_setOutlineColor(inv->slots[i].slot, outline);
        sfRectangleShape_setPosition(inv->slots[i].slot,
            inv->slots[i].slot_pos);
        sfRectangleShape_setSize(inv->slots[i].slot, (sfVector2f) {25, 25});
        sfRectangleShape_setFillColor(inv->slots[i].slot, intern);
    }
}

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfTexture *txt = sfTexture_createFromFile("assets/inv_menu.png", NULL);
    sfVector2f size = {1920, 1080};
    sfColor inv_color = sfColor_fromRGBA(0, 0, 0, 150);

    start_slots(inventory);
    inventory->inv_sprite = sfSprite_create();
    inventory->inv = sfRectangleShape_create();
    sfSprite_setTexture(inventory->inv_sprite, txt, sfTrue);
    sfRectangleShape_setSize(inventory->inv, size);
    sfRectangleShape_setFillColor(inventory->inv, inv_color);
    inventory->inv_pos.x = 0;
    inventory->inv_pos.y = 0;
    sfRectangleShape_setPosition(inventory->inv, inventory->inv_pos);
    free(txt);
    return inventory;
}

void init_notification_sprite(data_t *data)
{
    sfTexture *txt = sfTexture_createFromFile("assets/notif/notif.png", NULL);
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfTexture *vic = sfTexture_createFromFile("assets/effects/v_e.png", NULL);

    data->notif = malloc(sizeof(notif_t));
    data->notif->notif = sfSprite_create();
    data->notif->text = sfText_create();
    data->notif->victory_effect = sfSprite_create();
    data->notif->active = false;
    data->notif->clock = sfClock_create();
    data->notif->notif = sfSprite_create();
    sfSprite_setScale(data->notif->victory_effect, (sfVector2f){0.03, 0.03});
    sfText_setFont(data->notif->text, font);
    sfSprite_setTexture(data->notif->victory_effect, vic, sfTrue);
    sfSprite_setTexture(data->notif->notif, txt, sfTrue);
    sfSprite_setPosition(data->notif->notif, (sfVector2f){100, 100});
    sfSprite_setPosition(data->notif->victory_effect, (sfVector2f){100, 100});
    free(txt);
    free(vic);
}

static void init_tuto_map(tuto_t *tuto)
{
    sfTexture *txt = sfTexture_createFromFile("assets/tuto.png", NULL);
    sfTexture *top = sfTexture_createFromFile("assets/tuto_top.png", NULL);

    tuto->tuto = sfSprite_create();
    tuto->tuto_top = sfSprite_create();
    sfSprite_setTexture(tuto->tuto, txt, sfTrue);
    sfSprite_setTexture(tuto->tuto_top, top, sfTrue);
    free(txt);
    free(top);
}

tuto_t *init_tuto(void)
{
    tuto_t *tuto = malloc(sizeof(tuto_t));
    sfTexture *txt_h;
    sfTexture *effect;

    txt_h = sfTexture_createFromFile("assets/headers/h_tf.png", NULL);
    effect = sfTexture_createFromFile("assets/effects/v_e.png", NULL);
    tuto->clock = sfClock_create();
    tuto->finsish_effect = sfSprite_create();
    tuto->tuto_finsished = sfSprite_create();
    sfSprite_setTexture(tuto->tuto_finsished, txt_h, sfTrue);
    sfSprite_setTexture(tuto->finsish_effect, effect, sfTrue);
    sfSprite_setScale(tuto->tuto_finsished, (sfVector2f){0.8, 0.8});
    sfSprite_setScale(tuto->finsish_effect, (sfVector2f){0.2, 0.2});
    tuto->move = false;
    tuto->attack = false;
    tuto->inventory = false;
    init_tuto_map(tuto);
    free(txt_h);
    free(effect);
    return tuto;
}
