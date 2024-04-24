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
