/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void set_data(collision_t *collision, sfVector2f pos, int y, int s)
{
    collision[y].col_pos = pos;
    collision[y].collision = s;
    collision[y].col_sprite = sfRectangleShape_create();
    sfRectangleShape_setSize(collision[y].col_sprite, (sfVector2f){16, 16});
    sfRectangleShape_setPosition(
        collision[y].col_sprite, collision[y].col_pos);
    sfRectangleShape_setFillColor(collision[y].col_sprite, sfTransparent);
    sfRectangleShape_setOutlineThickness(collision[y].col_sprite, 1);
    sfRectangleShape_setOutlineColor(collision[y].col_sprite, sfRed);
}

char *file_content(char *buffer)
{
    FILE *fp = fopen("config_files/col_tuto.txt", "r");

    fread(buffer, 1, 50000, fp);
    return buffer;
}

static void init_collision_2(char *line, collision_t *collision)
{
    sfVector2f pos = (sfVector2f){0, 0};
    int x = 0;
    int h = 0;

    for (int y = 0; y < 14300; y++) {
        if (x >= 130) {
            x = 0;
            h++;
        }
        pos.x = x * 16;
        pos.y = (h * 16) - 16;
        set_data(collision, pos, y, atoi(line));
        x++;
        line = strtok(NULL, ",\n");
    }
}

collision_t *init_collision(void)
{
    collision_t *collision = malloc(sizeof(collision_t) * 14300);
    char *buffer = malloc(sizeof(char) * 50000);
    char *line = NULL;

    collision->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(collision->hitbox, (sfVector2f){10, 10});
    sfRectangleShape_setFillColor(collision->hitbox, sfRed);
    buffer = file_content(buffer);
    line = strtok(buffer, ",\n");
    init_collision_2(line, collision);
    free(buffer);
    return collision;
}
