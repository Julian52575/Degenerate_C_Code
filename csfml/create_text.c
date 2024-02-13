/*
** EPITECH PROJECT, 2023
** project_name
** File description:
** create_text
*/
#include "my_csfml.h"

sfText *create_text(sfFont *font, int size, char *string, sfColor color)
{
    sfText *t = sfText_create();
    sfText_setFont(t, font);
    sfText_setCharacterSize(t, size);
    if (string)
        sfText_setString(t, string);

    sfText_setColor(t, color);
    return t;
}
