/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void day_texutre(data_t *data, sfVector2f pos)
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
    sfSprite_setPosition(data->hud->meteo, pos);
    sfSprite_setScale(data->hud->meteo, (sfVector2f){1, 1.5});
    sfRenderWindow_drawSprite(data->window, data->hud->meteo, NULL);
    free(txt);
    i++;
}

static void night_display(data_t *data, sfVector2f pos)
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
    sfSprite_setPosition(data->hud->meteo, pos);
    sfSprite_setScale(data->hud->meteo, (sfVector2f){1, 1.5});
    sfRenderWindow_drawSprite(data->window, data->hud->meteo, NULL);
    free(txt);
    i++;
}

static void rain(data_t *data, sfVector2f pos)
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
    sfSprite_setPosition(data->hud->meteo, pos);
    sfSprite_setScale(data->hud->meteo, (sfVector2f){1, 1.5});
    sfRenderWindow_drawSprite(data->window, data->hud->meteo, NULL);
    free(txt);
    i++;
}

void change_texture(data_t *data)
{
    int x = (1920 / 3) - 1050;
    int y = (1080 / 2) - 40;
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f sprite_pos = {center.x - x, center.y - y};

    if (data->hud->meteo_status == 1)
        day_texutre(data, sprite_pos);
    if (data->hud->meteo_status == 2)
        night_display(data, sprite_pos);
    if (data->hud->meteo_status == 3)
        rain(data, sprite_pos);
}

void meteo_display(data_t *data)
{
    change_texture(data);
}
