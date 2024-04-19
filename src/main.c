/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "My_RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
}
