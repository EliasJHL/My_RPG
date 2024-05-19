/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void set_data_map(collision_t *collision, sfVector2f pos, int y, int s)
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

char *file_content_map(char *buffer)
{
    FILE *fp = fopen("config_files/col_map.txt", "r");

    fread(buffer, 1, 500000, fp);
    return buffer;
}

static void init_collision_2_map(char *line, collision_t *collision)
{
    sfVector2f pos = (sfVector2f){0, 0};
    int x = 0;
    int h = 0;

    for (int y = 0; y < 87040; y++) {
        if (x >= 320) {
            x = 0;
            h++;
        }
        pos.x = x * 16;
        pos.y = (h * 16) - 16;
        set_data_map(collision, pos, y, atoi(line));
        x++;
        line = strtok(NULL, ",\n");
    }
}

collision_t *init_collision_map(void)
{
    collision_t *collision = malloc(sizeof(collision_t) * 87040);
    char *buffer = malloc(sizeof(char) * 500000);
    char *line = NULL;

    buffer = file_content_map(buffer);
    line = strtok(buffer, ",\n");
    init_collision_2_map(line, collision);
    free(buffer);
    return collision;
}
