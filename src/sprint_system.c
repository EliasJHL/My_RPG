/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void init_sprint(data_t *data)
{
    data->sprint = malloc(sizeof(sprint_t));
    data->sprint->clock = sfClock_create();
    data->sprint->stamina = 100;
    data->sprint->stamina_rec = sfRectangleShape_create();
    sfRectangleShape_setFillColor(data->sprint->stamina_rec, sfWhite);
    sfRectangleShape_setSize(data->sprint->stamina_rec,
        (sfVector2f){1920 / 2, 20});
    sfRectangleShape_setPosition(data->sprint->stamina_rec,
        (sfVector2f){0, 1060});
    data->sprint->speed = 1;
}

static void display_stamina(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);

    sfRectangleShape_setPosition(data->sprint->stamina_rec,
        (sfVector2f){center.x - (1920 / 4), center.y + 235});
    sfRenderWindow_drawRectangleShape(data->window,
        data->sprint->stamina_rec, NULL);
}

static void stamina_system(data_t *data)
{
    double seconds = 0;

    seconds = sfTime_asSeconds(sfClock_getElapsedTime(data->sprint->clock));
    if (seconds >= 0.1) {
        if (data->sprint->stamina < 100)
            data->sprint->stamina += 1;
        sfClock_restart(data->sprint->clock);
    }
}

static void stamina_consomation(data_t *data)
{
    double seconds = 0;

    seconds = sfTime_asSeconds(sfClock_getElapsedTime(data->sprint->clock));
    if (seconds >= 0.1) {
        if (data->sprint->stamina > 0)
            data->sprint->stamina -= 2;
        sfClock_restart(data->sprint->clock);
    }
}

void adapt_rectangle_stamina(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f size = sfRectangleShape_getSize(data->sprint->stamina_rec);

    size.x = (1920 / 2) * (data->sprint->stamina / 100.0f);
    sfRectangleShape_setSize(data->sprint->stamina_rec, size);
    sfRectangleShape_setPosition(data->sprint->stamina_rec,
        (sfVector2f){center.x - (1920 / 4), center.y + 235});
    sfRenderWindow_drawRectangleShape(data->window,
        data->sprint->stamina_rec, NULL);
}

void sprint_check(data_t *data)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue) {
        if (data->sprint->stamina > 0)
            data->sprint->speed = 1.7;
        else
            data->sprint->speed = 1;
        stamina_consomation(data);
    } else {
        data->sprint->speed = 1;
        stamina_system(data);
    }
    adapt_rectangle_stamina(data);
    display_stamina(data);
}
