/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

int cooldown_notif(data_t *data, sfVector2f pos, sfVector2f center)
{
    double seconds;
    static int i = 0;
    sfClock *ck = sfClock_create();
    sfTime time = sfClock_getElapsedTime(ck);
    double time_elapsed = sfTime_asSeconds(time);

    data->notif->elapsed_time = sfClock_getElapsedTime(data->notif->clock);
    seconds = sfTime_asSeconds(data->notif->elapsed_time);
    if (seconds >= 0 && seconds <= 2 && time_elapsed >= 0.15)
        i += 1;
    if (seconds >= 6 && seconds <= 8 && time_elapsed >= 0.15)
        i -= 1;
    if (seconds >= 8) {
        i = 0;
        data->notif->active = false;
        data->notif->content = 0;
        sfClock_restart(data->notif->clock);
    }
    sfClock_restart(ck);
    return i;
}

void sprite_notif(data_t *data)
{
    sfTexture *txt;

    if (data->notif->content == 1)
        txt = sfTexture_createFromFile("assets/notif/demo.png", NULL);
    sfSprite_setTexture(data->notif->notif_content, txt, sfTrue);
}

/*pos.x -= */
void notification_display(data_t *data)
{
    sfVector2f center = sfView_getCenter(data->player->camera);
    sfVector2f pos = {center.x + 300, center.y - 200};

    sfSprite_setScale(data->notif->notif, (sfVector2f){0.8, 0.8});
    sfSprite_setScale(data->notif->notif_content, (sfVector2f){0.8, 0.8});
    sprite_notif(data);
    cooldown_notif(data, pos, center);
    sfSprite_setPosition(data->notif->notif, pos);
    sfSprite_setPosition(data->notif->notif_content, pos);
    sfRenderWindow_drawSprite(data->window, data->notif->notif, NULL);
    sfRenderWindow_drawSprite(data->window, data->notif->notif_content, NULL);
}

void notification(data_t *data, int nb)
{
    if (data->notif->active == true)
        return;
    data->notif->content = nb;
    data->notif->active = true;
}
