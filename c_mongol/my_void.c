/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "../include/my.h"
#include "../include/void.h"

void **create_void_tab(int nb_elem)
{
    void **tab = malloc(sizeof(void *) * nb_elem + 1);

    tab[nb_elem] = NULL;
    return tab;
}

int my_void_len(void **tab)
{
    int i = 0;

    if (tab == NULL)
        return 0;
    for (; tab[i]; i ++);
    return i;
}

void **void_add(void **tab, void *e)
{
    int nb[] = {my_void_len(tab), 0};
    void **dest = malloc(sizeof(void *) * (!(nb[0] == 0) * nb[0] +
    (nb[0] == 0)) + 1);

    for (; nb[1] < nb[0]; nb[1] ++)
        dest[nb[1]] = tab[nb[0]];
    dest[nb[1]] = e;
    dest[nb[1] + (nb[1] == 0)] = NULL;
    return dest;
}

/*add_elem in struct void_t*/
int add_in_tab(void **tab, void *val, const char *type)
{
    (void) tab;
    (void) val;
    (void) type;
    return 0;
}

void_t *create_void(void)
{
    void_t *s = malloc(sizeof(void_t));

    s->add_elem = &add_in_tab;
    s->get_tab = NULL;
    return s;
}
