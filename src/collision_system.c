/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

collision_t *get_rectangle_above_player(data_t *data)
{
    sfVector2f player_pos = data->player->player_pos;
    sfVector2f grid_pos = {player_pos.x / 16, (player_pos.y - 16) / 16};
    sfVector2f col_pos;

    for (int i = 0; i < 14300; i++) {
        col_pos = data->collision[i].col_pos;
        if (col_pos.x >= grid_pos.x - 16 && col_pos.x <= grid_pos.x + 16 &&
            col_pos.y >= grid_pos.y - 16 && col_pos.y <= grid_pos.y + 16) {
            return &data->collision[i];
        }
    }
    return NULL;
}

int collision_check(data_t *data)
{
    collision_t *rectangle = NULL;

    rectangle = get_rectangle_above_player(data);
    if (UP(event) && rectangle != NULL) {
        if (rectangle->collision != 0)
            return 1;
    }
    return 0;
}

static void set_data(collision_t *collision, sfVector2f pos, int y)
{
    collision[y].col_pos = pos;
    collision[y].collision = 1;
    collision[y].col_sprite = sfRectangleShape_create();
    sfRectangleShape_setSize(collision[y].col_sprite, (sfVector2f){16, 16});
    sfRectangleShape_setPosition(
        collision[y].col_sprite, collision[y].col_pos);
    sfRectangleShape_setFillColor(collision[y].col_sprite, sfTransparent);
    sfRectangleShape_setOutlineThickness(collision[y].col_sprite, 1);
    sfRectangleShape_setOutlineColor(collision[y].col_sprite, sfRed);
}

collision_t *init_collision(void)
{
    collision_t *collision = malloc(sizeof(collision_t) * 14300);
    int x = 0;
    int h = 0;
    sfVector2f pos = (sfVector2f){0, 0};

    for (int y = 0; y < 14300; y++) {
        if (x > 110) {
            x = 0;
            h++;
        }
        pos.x = x * 16;
        pos.y = h * 16;
        set_data(collision, pos, y);
        x++;
    }
    return collision;
}
