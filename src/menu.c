/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

int check_click_btn(data_t *data, sfEvent event)
{
    FILE *save = fopen("saves/save_1.rpg", "rw");

    if (sfMouse_isButtonPressed(sfMouseLeft) && is_hover(data,
        data->menu_window->newgame)) {
        data->menu_mode = false;
        data->tuto_mode = true;
        return 1;
    }
    fclose(save);
    return 0;
}

static int check_event(data_t *data, sfEvent event)
{
    while (sfRenderWindow_pollEvent(data->window, &event)) {
        if (check_click_btn(data, event) == 1)
            return 1;
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
    }
    return 0;
}

static void draw_btn_2(data_t *data)
{
    if (is_hover(data, data->menu_window->options))
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->options_hover, NULL);
    else
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->options, NULL);
    if (is_hover(data, data->menu_window->credits))
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->credits_hover, NULL);
    else
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->credits, NULL);
    if (is_hover(data, data->menu_window->exit))
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->exit_hover, NULL);
    else
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->exit, NULL);
}

void draw_btn(data_t *data)
{
    if (is_hover(data, data->menu_window->newgame))
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->newgame_hover, NULL);
    else
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->newgame, NULL);
    if (is_hover(data, data->menu_window->loadgame))
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->loadgame_hover, NULL);
    else
        sfRenderWindow_drawSprite(data->window,
            data->menu_window->loadgame, NULL);
    draw_btn_2(data);
}

static void set_data(data_t *data)
{
    if (data->menu_window->zoom_mode == true) {
        data->menu_window->bg_pos.x -= 1;
        data->menu_window->bg_pos.y -= 0.8;
        data->menu_window->zoom += 0.001;
    } else {
        data->menu_window->bg_pos.x += 1;
        data->menu_window->bg_pos.y += 0.8;
        data->menu_window->zoom -= 0.001;
    }
    if (data->menu_window->zoom >= 3)
        data->menu_window->zoom_mode = false;
    if (data->menu_window->zoom <= 1)
        data->menu_window->zoom_mode = true;
}

static void zoom_bg(data_t *data)
{
    double seconds;

    data->menu_window->elapsed_time = sfClock_getElapsedTime(
        data->menu_window->clock);
    seconds = sfTime_asSeconds(data->menu_window->elapsed_time);
    if (seconds >= 0) {
        set_data(data);
        sfSprite_setPosition(data->menu_window->menu_bg,
            data->menu_window->bg_pos);
        sfSprite_setScale(data->menu_window->menu_bg,
            (sfVector2f){data->menu_window->zoom, data->menu_window->zoom});
        sfClock_restart(data->menu_window->clock);
    }
}

int menu(data_t *data)
{
    check_event(data, data->event);
    zoom_bg(data);
    sfRenderWindow_clear(data->window, sfColor_fromRGB(80, 140, 180));
    sfRenderWindow_drawSprite(data->window, data->menu_window->menu_bg, NULL);
    sfRenderWindow_drawSprite(data->window,
        data->menu_window->container, NULL);
    draw_btn(data);
    sfRenderWindow_display(data->window);
    return 0;
}
