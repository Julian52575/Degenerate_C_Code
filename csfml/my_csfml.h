#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>


sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y,
                                    unsigned int bpp, char *title);

sfSprite *create_sprite(char *image_path, float x_scale, float y_scale, sfIntRect *rect);
sfText *create_text(sfFont *font, int size, char *string, sfColor color);
void close_window(sfRenderWindow *ct);
