/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void init_life(data_t *data)
{
    int pos_x = 0;
    life_t *life = NULL;
    life_t *node = NULL;
    sfTexture *heart;

    heart = sfTexture_createFromFile("assets/life/active.png", NULL);
    for (int i = 0; i < 10; i++) {
        node = malloc(sizeof(life_t));
        node->heart = sfSprite_create();
        sfSprite_setTexture(node->heart, heart, sfTrue);
        node->heart_pos.x += pos_x;
        node->heart_pos.y = 0;
        sfSprite_setPosition(node->heart, node->heart_pos);
        pos_x += 18;
        node->next = life;
        life = node;
    }
    data->player->life_hud = life;
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
        inv->slots[i].item_id = 001;
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
