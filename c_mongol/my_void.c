/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "void.h"

int my_void_len(void **tab)
{
    int i = 0;

    if (tab == NULL)
        return i;
    for (; tab[i]; i ++);
    return i;
}


static int my_putchar(long c)
{
    write(1, &c, 1);
    return 0;
}

static int my_put_nbr(long nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    } else {
        my_putchar(nb + '0');
    }
    my_putchar('\n');
    return 0;
}

static int my_putstr(char const *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    write(1, str, i);
    my_putchar('\n');
    return 0;
}

static int my_show_array(char *const tab[])
{
    for (int i = 0; tab[i]; i ++)
        my_putstr(tab[i]);
    return 0;
}

static int my_putlist(node_t **l, int id_list)
{
    my_putstr("Liste lv");
    my_put_nbr(id_list);
    my_putstr("{\n");
    for (node_t *node = *l; node; node = node->CHANGE_NODE)
        display_void(node->NODE_VAL, node->type_val, id_list + 1);
    my_putstr("} Liste lv");
    my_put_nbr(id_list);
    my_putchar('\n');
    return 0;
}

/*{len, ...}*/
int my_putint(int *l)
{
    my_putchar('{');
    for (int i = 1; i - 1 < l[0]; i ++) {
        my_put_nbr(l[i]);
        if (i < l[0])
            my_putstr(", ");
    }
    my_putstr("}\n");
    return 0;
}

/*{tab_elem, tab_type}*/
int my_putvoid(void **tab, int id_list)
{
    void **tab_elem = tab[0];
    enum type *tab_type = (enum type *)tab[1];

    my_putstr("Tableau lv");
    my_put_nbr(id_list);
    my_putstr("{\n");
    for (int i = 0; tab_elem[i]; i ++)
        display_void((void *)tab_elem[i], tab_type[i], id_list + 1);
    my_putstr("} Tableau lv");
    my_put_nbr(id_list);
    my_putchar('\n');
    return 0;
}

int display_void(void *e, enum type t, int id_list)
{
    if (t == INT)
        return my_put_nbr((long)e);
    if (t == CHAR)
        return my_putchar((long)e);
    if (t == STR)
        return my_putstr((char *)e);
    if (t == TABSTR)
        return my_show_array((char **)e);
    if (t == TABINT)
        return my_putint((int *) e);
    if (t == TABVOID)
        return my_putvoid((void **)e, id_list);
    if (t == LIST)
        return my_putlist((node_t **)e, id_list);
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
