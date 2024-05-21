/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int length = 0;
    char temp = NULL;

    if (str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        length++;
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return str;
}

char *int_to_string(int nb)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;

    for (i = 0; nb > 0; i++) {
        str[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}

int is_hover(data_t *data, sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse_pos_pixel = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(data->window,
        mouse_pos_pixel, sfRenderWindow_getView(data->window));

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y))
        return 1;
    return 0;
}

int is_clicked_slot(data_t *data, sfRectangleShape *slot)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(slot);
    sfVector2i mouse_pos_pixel = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(data->window,
        mouse_pos_pixel, sfRenderWindow_getView(data->window));

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y))
        return 1;
    return 0;
}

int is_clicked(data_t *data, sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);
    sfVector2i mouse_pos_pixel = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(data->window,
        mouse_pos_pixel, sfRenderWindow_getView(data->window));

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y))
        return 1;
    return 0;
}
