/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** Elias Josué HAJJAR LLAUQUEN
*/

#include "../include/my.h"

void set_npc_info_2(npc_t *newNode, char *name, sfVector2f pos, int nb)
{
    sfFloatRect size = sfSprite_getGlobalBounds(newNode->sprite);

    sfSprite_setOrigin(newNode->sprite,
        (sfVector2f){(size.width / nb) / 2, size.height / 2});
    sfSprite_setPosition(newNode->sprite, (sfVector2f)
        {pos.x + (size.width / nb) / 2, pos.y + 25});
    newNode->npc_name = name;
    newNode->pos = pos;
    newNode->nb_frames = nb;
    newNode->active = true;
    newNode->clock = sfClock_create();
    newNode->next = NULL;
    newNode->to_talk = true;
    newNode->is_sign = false;
    newNode->txt_sign = NULL;
}

npc_t *set_npc_info(char *name, sfVector2f pos, int nb)
{
    npc_t *newNode = malloc(sizeof(npc_t));
    char *path = malloc(sizeof("assets/items") + sizeof(name) + 6);
    sfTexture *txt = NULL;

    strcpy(path, "assets/npcs/");
    strcat(path, name);
    strcat(path, ".png");
    newNode->sprite = sfSprite_create();
    txt = sfTexture_createFromFile(path, NULL);
    if (txt == NULL) {
        txt = sfTexture_createFromFile("assets/npcs/none.png", NULL);
        sfSprite_setTexture(newNode->sprite, txt, sfTrue);
    } else {
        sfSprite_setTexture(newNode->sprite, txt, sfTrue);
    }
    set_npc_info_2(newNode, name, pos, nb);
    free(txt);
    free(path);
    return newNode;
}

// the name of npc need to be the same of
// his texture name (jean → jean.png on assets/npcs)
void add_npc(data_t *data, char *name, sfVector2f pos, int nb_frames)
{
    npc_t *node = data->npc;

    if (node == NULL)
        data->npc = set_npc_info(name, pos, nb_frames);
    else {
        while (node->next != NULL)
            node = node->next;
        node->next = set_npc_info(name, pos, nb_frames);
    }
}

static void config_txt(char *path, npc_t *newNode, char *text)
{
    sfTexture *txt = NULL;

    txt = sfTexture_createFromFile(path, NULL);
    if (txt == NULL) {
        txt = sfTexture_createFromFile("assets/npcs/none_talk.png", NULL);
        sfSprite_setTexture(newNode->talk_sprite, txt, sfTrue);
    } else {
        sfSprite_setTexture(newNode->talk_sprite, txt, sfTrue);
    }
    if (strcmp(text, "NULL") != 0) {
        newNode->is_sign = true;
        newNode->dialog = NULL;
        newNode->txt_sign = text;
    } else {
        newNode->is_sign = false;
        newNode->txt_sign = NULL;
        config_dialog_npc(newNode);
    }
    free(txt);
}

void config_npc(char *name, data_t *data, bool is_tuto, char *text)
{
    char *path = malloc(sizeof("assets/npcs/") + sizeof(name) + 10);
    npc_t *node = data->npc;

    strcpy(path, "assets/npcs/");
    strcat(path, name);
    strcat(path, "_talk.png");
    while (node != NULL) {
        if (strcmp(node->npc_name, name) == 0) {
            node->talk_sprite = sfSprite_create();
            config_txt(path, node, text);
            node->to_talk = true;
            node->is_tuto = is_tuto;
        }
        node = node->next;
    }
    free(path);
}

//give txt if it's only a sign else send "NULL"
//if u want to set some signs u need to call him "sign_1" ; "sign_2" ; ...
// And create the sprite sign_1.png ; sign_2.png ; ...
static void init_npc_2(data_t *data)
{
    config_npc("sign", data, true, "Hey welcome in the pixel"
        " world\nadventurer !          ");
    config_npc("sign_1", data, true, "This is a tutorial map\n"
        "You can interact with 'F'          ");
    config_npc("jean", data, true, "NULL");
}

void init_npc(data_t *data)
{
    add_npc(data, "sign", (sfVector2f){855, 900}, 1);
    add_npc(data, "sign_1", (sfVector2f){855, 800}, 1);
    add_npc(data, "jean", (sfVector2f){855, 700}, 1);
    init_npc_2(data);
}
