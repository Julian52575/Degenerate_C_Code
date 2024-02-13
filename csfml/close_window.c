#include "my_csfml.h"

void close_window(sfRenderWindow *window)
{
    sfEvent evt = {0};

    while (sfRenderWindow_pollEvent(window, &evt) == sfTrue) {
        if (evt.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}
