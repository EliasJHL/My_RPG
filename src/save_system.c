/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void write_inventory(FILE *file, inventory_t *inventory)
{
    for (int i = 0; i < 48; i++) {
        fwrite(&inventory[i], sizeof(inventory_t), 1, file);
        fwrite(&inventory[i].slots, sizeof(int), 1, file);
    }
}

inventory_t *read_inventory(FILE *file)
{
    inventory_t *inventory = malloc(sizeof(inventory_t) * 48);

    for (int i = 0; i < 48; i++) {
        fread(&inventory[i], sizeof(inventory_t), 1, file);
        fread(&inventory[i].slots, sizeof(int), 1, file);
    }
    return inventory;
}

void save_game(data_t *data, int slot)
{
    FILE *save;
    char *name = malloc(sizeof(char) * 20);

    sprintf(name, "saves/save_%d.rpg", slot);
    save = fopen(name, "wb");
    fwrite(&data->player->life, sizeof(int), 1, save);
    fwrite(&data->player->player_pos, sizeof(sfVector2f), 1, save);
    fwrite(&data->selected_id, sizeof(int), 1, save);
    fwrite(&data->hud->item_slot_nb, sizeof(int), 1, save);
    fwrite(&data->hud->item_hold, sizeof(int), 1, save);
    fwrite(&data->hud->meteo_status, sizeof(int), 1, save);
    write_inventory(save, data->inv);
    fclose(save);
    free(name);
}

void load_game(data_t *data, int slot)
{
    FILE *save;
    char *name = malloc(sizeof(char) * 20);

    sprintf(name, "saves/save_%d.rpg", slot);
    save = fopen(name, "rb");
    fread(&data->player->life, sizeof(int), 1, save);
    fread(&data->player->player_pos, sizeof(sfVector2f), 1, save);
    fread(&data->selected_id, sizeof(int), 1, save);
    fread(&data->hud->item_slot_nb, sizeof(int), 1, save);
    fread(&data->hud->item_hold, sizeof(int), 1, save);
    fread(&data->hud->meteo_status, sizeof(int), 1, save);
    sfSprite_setPosition(data->player->player_sprite,
        data->player->player_pos);
    data->inv = read_inventory(save);
    fclose(save);
    free(name);
}
