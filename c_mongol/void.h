/*
** EPITECH PROJECT, 2023
** Cmongole
** File description:
** void lib
*/

#ifndef VOIDH
#define VOIDH

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

enum type {INT, CHAR, STR, TABSTR, TABINT, TABVOID, LIST};

/* node pouvant etre modifer */
typedef struct node_s {
    struct node_s *prev;
    void *value;
    enum type type_val;
    int id;
    struct node_s *next;
} node_t;

typedef struct void_s {
    void *elem;
    int type;
    int (*print)(void *);
} void_t;


#define CHANGE_NODE next
#define NODE_VAL value

int display_void(void *e, enum type t, int id_list);
#endif
