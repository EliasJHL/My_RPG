/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void init_loadgame(menu_window_t *menu)
{
    sfTexture *txt = sfTexture_createFromFile(
        "assets/menu/loadgame.png", NULL);
    sfTexture *txt_h = sfTexture_createFromFile(
        "assets/menu/loadgame_hover.png", NULL);

    menu->loadgame = sfSprite_create();
    menu->loadgame_hover = sfSprite_create();
    sfSprite_setTexture(menu->loadgame, txt, sfTrue);
    sfSprite_setTexture(menu->loadgame_hover, txt_h, sfTrue);
    sfSprite_setPosition(menu->loadgame, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 290});
    sfSprite_setPosition(menu->loadgame_hover, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 290});
    sfSprite_setScale(menu->loadgame, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(menu->loadgame_hover, (sfVector2f){3.5, 3.5});
    free(txt);
    free(txt_h);
}

static void init_exit(menu_window_t *menu)
{
    sfTexture *txt = sfTexture_createFromFile(
        "assets/menu/exit.png", NULL);
    sfTexture *txt_h = sfTexture_createFromFile(
        "assets/menu/exit_hover.png", NULL);

    menu->exit = sfSprite_create();
    menu->exit_hover = sfSprite_create();
    sfSprite_setTexture(menu->exit, txt, sfTrue);
    sfSprite_setTexture(menu->exit_hover, txt_h, sfTrue);
    sfSprite_setPosition(menu->exit, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 560});
    sfSprite_setPosition(menu->exit_hover, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 560});
    sfSprite_setScale(menu->exit, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(menu->exit_hover, (sfVector2f){3.5, 3.5});
    free(txt);
    free(txt_h);
}

static void init_credits(menu_window_t *menu)
{
    sfTexture *txt = sfTexture_createFromFile(
        "assets/menu/credits.png", NULL);
    sfTexture *txt_h = sfTexture_createFromFile(
        "assets/menu/credits_hover.png", NULL);

    menu->credits = sfSprite_create();
    menu->credits_hover = sfSprite_create();
    sfSprite_setTexture(menu->credits, txt, sfTrue);
    sfSprite_setTexture(menu->credits_hover, txt_h, sfTrue);
    sfSprite_setPosition(menu->credits, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 470});
    sfSprite_setPosition(menu->credits_hover, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 470});
    sfSprite_setScale(menu->credits, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(menu->credits_hover, (sfVector2f){3.5, 3.5});
    free(txt);
    free(txt_h);
}

static void init_options(menu_window_t *menu)
{
    sfTexture *txt = sfTexture_createFromFile(
        "assets/menu/options.png", NULL);
    sfTexture *txt_h = sfTexture_createFromFile(
        "assets/menu/option_hover.png", NULL);

    menu->options = sfSprite_create();
    menu->options_hover = sfSprite_create();
    sfSprite_setTexture(menu->options, txt, sfTrue);
    sfSprite_setTexture(menu->options_hover, txt_h, sfTrue);
    sfSprite_setPosition(menu->options, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 380});
    sfSprite_setPosition(menu->options_hover, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 380});
    sfSprite_setScale(menu->options, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(menu->options_hover, (sfVector2f){3.5, 3.5});
    free(txt);
    free(txt_h);
}

static void init_start(menu_window_t *menu)
{
    sfTexture *txt = sfTexture_createFromFile(
        "assets/menu/newgame.png", NULL);
    sfTexture *txt_h = sfTexture_createFromFile(
        "assets/menu/newgame_hover.png", NULL);

    menu->newgame = sfSprite_create();
    menu->newgame_hover = sfSprite_create();
    sfSprite_setTexture(menu->newgame, txt, sfTrue);
    sfSprite_setTexture(menu->newgame_hover, txt_h, sfTrue);
    sfSprite_setPosition(menu->newgame, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 200});
    sfSprite_setPosition(menu->newgame_hover, (sfVector2f)
        {(1500 / 2) - (144 / 2) * 3.5, 200});
    sfSprite_setScale(menu->newgame, (sfVector2f){3.5, 3.5});
    sfSprite_setScale(menu->newgame_hover, (sfVector2f){3.5, 3.5});
    free(txt);
    free(txt_h);
}

void init_holder(menu_window_t *menu)
{
    sfTexture *txt = sfTexture_createFromFile("assets/menu/holder.png", NULL);

    menu->container = sfSprite_create();
    sfSprite_setTexture(menu->container, txt, sfTrue);
    sfSprite_setPosition(menu->container, (sfVector2f)
        {(1500 / 2) - (768 / 2), (800 / 2) - (560 / 2) + 30});
    sfSprite_setScale(menu->container, (sfVector2f){1, 1});
}

menu_window_t *init_menu_window(void)
{
    menu_window_t *menu = malloc(sizeof(menu_window_t));
    sfTexture *txt = sfTexture_createFromFile("assets/menu/menu_bg.png", NULL);

    menu->menu_bg = sfSprite_create();
    sfSprite_setTexture(menu->menu_bg, txt, sfTrue);
    sfSprite_setPosition(menu->menu_bg, (sfVector2f){0, 0});
    init_start(menu);
    init_holder(menu);
    init_loadgame(menu);
    init_options(menu);
    init_credits(menu);
    init_exit(menu);
    return menu;
}
