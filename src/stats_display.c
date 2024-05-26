/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

static void set_string_stats_4(data_t *data)
{
    char *life_str = malloc(sizeof(char) * 100);

    sfText_setColor(data->inv->defense_stat, sfBlack);
    sfText_setCharacterSize(data->inv->defense_stat, 40);
    sfText_setScale(data->inv->defense_stat, (sfVector2f){0.25, 0.25});
    sprintf(life_str, "______________________\nDefense : %d:(10 + %d)",
        data->player->defense_stat, data->player->defense_stat - 10);
    sfText_setString(data->inv->defense_stat, life_str);
    free(life_str);
}

static void set_string_stats_3(data_t *data)
{
    char *attack_str = malloc(sizeof(char) * 100);

    sfText_setColor(data->inv->attack_stat, sfBlack);
    sfText_setCharacterSize(data->inv->attack_stat, 40);
    sfText_setScale(data->inv->attack_stat, (sfVector2f){0.25, 0.25});
    sprintf(attack_str, "______________________\nAttack : %d:(10 + %d)",
        data->player->attack_stat, data->player->attack_stat - 10);
    sfText_setString(data->inv->attack_stat, attack_str);
    free(attack_str);
}

static void set_string_stats_2(data_t *data)
{
    char *player_name = malloc(sizeof(char) * 50);

    sfText_setColor(data->inv->Player_name, sfBlack);
    sfText_setCharacterSize(data->inv->Player_name, 40);
    sfText_setScale(data->inv->Player_name, (sfVector2f){0.25, 0.25});
    sprintf(player_name, "Name : Enzo Lobato Coutinho\n");
    sfText_setString(data->inv->Player_name, player_name);
    free(player_name);
}

static void set_string_stats_1(data_t *data)
{
    char *lvl_str = malloc(sizeof(char) * 100);

    sfText_setColor(data->inv->lvl_stat, sfBlack);
    sfText_setCharacterSize(data->inv->lvl_stat, 40);
    sfText_setScale(data->inv->lvl_stat, (sfVector2f){0.25, 0.25});
    sprintf(lvl_str, "______________________\nLVL | XP : %d:%d\n"
        "XP to next level : %d", data->player->level,
        data->player->xp, data->player->xp_to_next);
    sfText_setString(data->inv->lvl_stat, lvl_str);
    free(lvl_str);
}

void set_position(data_t *data, sfVector2f bg_pos)
{
    sfRectangleShape_setPosition(data->inv->bg_player,
        (sfVector2f) {bg_pos.x, bg_pos.y - 20});
    sfText_setPosition(data->inv->lvl_stat, (sfVector2f){bg_pos.x + 130,
        bg_pos.y - 10});
    sfText_setPosition(data->inv->Player_name, (sfVector2f){bg_pos.x + 130,
        bg_pos.y - 20});
    sfText_setPosition(data->inv->attack_stat, (sfVector2f){bg_pos.x + 130,
        bg_pos.y + 40});
    sfText_setPosition(data->inv->defense_stat, (sfVector2f){bg_pos.x + 130,
        bg_pos.y + 70});
}

void inventory_menu_2(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f bg_pos = {center.x - 147, center.y - 123};

    set_string_stats_1(data);
    set_string_stats_2(data);
    set_string_stats_3(data);
    set_string_stats_4(data);
    set_position(data, bg_pos);
    sfRenderWindow_drawRectangleShape(data->window,
        data->inv->bg_player, NULL);
    sfRenderWindow_drawText(data->window, data->inv->lvl_stat, NULL);
    sfRenderWindow_drawText(data->window, data->inv->Player_name, NULL);
    sfRenderWindow_drawText(data->window, data->inv->attack_stat, NULL);
    sfRenderWindow_drawText(data->window, data->inv->defense_stat, NULL);
}
