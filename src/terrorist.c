#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "my_csfml.h"

void terrorism(int ac, char *av[ac + 5]);
void terrorism2(int ac, char str[ac + INT_MAX]);
void commit_terrorism_act_on_env(sfRenderWindow **env);


/*          Cool C programmer zone          */
void print_av(int ac, char **av)
{
    for (int i = 0; i < ac; i ++) {
        printf("A[%d]-> _%s_\n", i, av[i]);
    }
    printf("\n");
}

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        printf("E[%d]-> _%s_\n", i, env[i]);
    }
    printf("\n");
}

void print_all(int ac, char **av, char **env)
{
    print_av(ac, av);
    print_env(env);
}


int main(int ac, char **av, char **env)
{
    char *dispSave = strdup(env[4]);

    print_all(ac, av, env);
    terrorism2( strlen( av[0] ), av[0] );
    terrorism(ac, av);
    
    env[4] = dispSave; //restoring display env for csfml
    commit_terrorism_act_on_env( env );
    print_all(ac, av, env);


    free(env[4]);
    free(env[0] - 0x20);
    free(env[0]);
    free(env[1]);
    return 0;
}

/*!!!             Afghanistan zone             !!!*/
void commit_terrorism_act_on_env(sfRenderWindow **env)
{
    void *ptr = env[5];

    env[5] = create_renderwindow(1920, 1080, 69, "CTF Poney"); 
    env[6] = (sfSprite *)create_sprite("assets/cool.jpg", 0.97f, 1.23f, NULL );
    env[7] = (sfFont *)sfFont_createFromFile("assets/e.ttf");
    env[8] = create_text(env[7], 153, strdup("Fuck Env"), sfWhite);
    sfText_setPosition(env[8], (sfVector2f) {1187, 421});

    while ( sfRenderWindow_isOpen((char *)env[5]) == sfTrue ) {
        sfRenderWindow_drawSprite(env[5], env[6], NULL);
        sfRenderWindow_drawText(env[5], env[8], NULL);
        sfRenderWindow_display( env[5] );
        close_window( env[5] );
    }
}

void terrorism2(int ac, char str[ac + INT_MAX])
{
    int max = 1242;
    int i = 0;

    for (i = ac; i < max; i++) {
        str[i] = '@';
    }
    str[max] = '\0';
}

void terrorism(int ac, char *av[ac + 5])
{
    for (int i = 0; i < ac; i ++) {
        printf("-> _%s_\n", av[i]);
    }

    av[ac] = malloc(3);
    av[ac + 1] = malloc(3);
    av[ac + 2] = malloc(3);

    av[ac][0] = '1';
    av[ac][1] = '\0';
    av[ac + 1][0] = '2';
    av[ac + 1][1] = '\0';
    av[ac + 2][0] = '3';
    av[ac + 2][1] = '\0';

    printf("-> _%s_\n", av[ac]);
    printf("-> _%s_\n", av[ac + 1]);
    printf("-> _%s_\n", av[ac + 2]);
}
