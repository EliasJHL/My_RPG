/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void background(data_t *data)
{
    sfRectangleShape *bg = sfRectangleShape_create();
    sfVector2f size = {10000, 10000};

    sfRectangleShape_setSize(bg, size);
    if (data->hud->meteo_status == 1)
        sfRectangleShape_setFillColor(bg, sfCyan);
    if (data->hud->meteo_status == 2)
        sfRectangleShape_setFillColor(bg, sfBlack);
    if (data->hud->meteo_status == 3)
        sfRectangleShape_setFillColor(bg, sfColor_fromRGB(150, 150, 150));
    sfRectangleShape_setPosition(bg, (sfVector2f){0, 0});
    sfRenderWindow_drawRectangleShape(data->window, bg, NULL);
}

static void day_texutre(data_t *data)
{
    static int i;
    char str[30] = "assets/meteo_hud/day/";
    sfTexture *txt = NULL;

    if (i == 10 || i == 0)
        i = 1;
    str[21] = i + '0';
    str[22] = '.';
    str[23] = 'p';
    str[24] = 'n';
    str[25] = 'g';
    str[26] = '\0';
    txt = sfTexture_createFromFile(str, NULL);
    data->hud->meteo = sfSprite_create();
    sfSprite_setTexture(data->hud->meteo, txt, sfTrue);
    free(txt);
    i++;
}

static void night_display(data_t *data)
{
    static int i;
    char str[30] = "assets/meteo_hud/night/";
    sfTexture *txt = NULL;

    if (i == 10 || i == 0)
        i = 1;
    str[23] = i + '0';
    str[24] = '.';
    str[25] = 'p';
    str[26] = 'n';
    str[27] = 'g';
    str[28] = '\0';
    txt = sfTexture_createFromFile(str, NULL);
    data->hud->meteo = sfSprite_create();
    sfSprite_setTexture(data->hud->meteo, txt, sfTrue);
    free(txt);
    i++;
}

static void rain(data_t *data)
{
    static int i;
    char str[30] = "assets/meteo_hud/rain/";
    sfTexture *txt = NULL;

    if (i == 10 || i == 0)
        i = 1;
    str[22] = i + '0';
    str[23] = '.';
    str[24] = 'p';
    str[25] = 'n';
    str[26] = 'g';
    str[27] = '\0';
    txt = sfTexture_createFromFile(str, NULL);
    data->hud->meteo = sfSprite_create();
    sfSprite_setTexture(data->hud->meteo, txt, sfTrue);
    free(txt);
    i++;
}

void change_texture(data_t *data)
{
    double seconds;
    int x = 385;
    int y = 270;
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x + x, center.y - y};

    data->hud->time_meteo = sfClock_getElapsedTime(data->hud->clock_meteo);
    seconds = sfTime_asSeconds(data->hud->time_meteo);
    if (seconds >= 0.15) {
        if (data->hud->meteo_status == 1)
            day_texutre(data);
        if (data->hud->meteo_status == 2)
            night_display(data);
        if (data->hud->meteo_status == 3)
            rain(data);
        sfClock_restart(data->hud->clock_meteo);
    }
    sfSprite_setPosition(data->hud->meteo, sprite_pos);
}

void meteo_display(data_t *data)
{
    change_texture(data);
    sfRenderWindow_drawSprite(data->window, data->hud->meteo, NULL);
}
