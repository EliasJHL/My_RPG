/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

/*
void item_selected_drsaw(data_t *data)
{
    sfVector2i mouse_pos_pix = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f mouse_pos = sfRenderWindow_mapPixelToCoords(data->window,
        mouse_pos_pix, sfRenderWindow_getView(data->window));
    items_t *current = data->items;

    printf("%s\n", data->selected_item ? "true" : "false");
    if (!data->selected_item)
        return;
    while (current != NULL) {
        if (current->item_id == data->id) {
            data->inv->item_selected = current->item;
            sfSprite_setPosition(data->inv->item_selected, mouse_pos);
            data->inv->status = true;
            return;
        }
        current = current->next;
    }
}*/
