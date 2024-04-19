/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void event_handler(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "My_RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            event_handler(window, event);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    return 0;
}
