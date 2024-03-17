

// Long int into str
#include <stdint.h>
#include <stdio.h>

int
write(int fd, void* a, int nb);

static unsigned int
my_strlen(char *str)
{
    return (str[0] == '\0' ? 0 : 1 + my_strlen( str + 1 ) );
}

static inline void
bufferize_print(const char *msg, size_t buf_size)
{
    uint64_t buffer =   0;
    char *ptr   =   (void *) 0;
    size_t valid[] = { 1,2,4,8 };

    for (size_t i = 0; i <= 3; i++) {
        if ( valid[i] == buf_size )
            goto chokbar_de_bz;
    }
    return;

chokbar_de_bz:
    for (char i = buf_size; i > 0; --i) {
        buffer += msg[i];
        buffer = buffer << 8;
    }
    buffer += msg[0];
    ptr = &(&buffer)[0];
    for (int i = 0; i < (char) buf_size; i++) {
        write(1, &(ptr[i]), 1);
    }
}

int
main(int ac, char **av)
{
    size_t length       =   0;
    size_t index        =   0;
    size_t dif          =   0;
    size_t buf_size     =   0;
    char   usage[]      = "Usage:\t./intbuffer {message}\n";

    if (ac != 2) {
        write(2, &(usage[0]), my_strlen(usage));
        return 84;
    }
    length = my_strlen(av[1]);
    if ( length == 0 )
        return 84;

    do {
        dif = length - index;
        if (dif > 8) {
            buf_size = 8;
        } else if (dif > 4) {
            buf_size = 4;
        } else if (dif > 2) {
            buf_size = 2;
        } else {
            buf_size = 1;
        }
        bufferize_print( &(av[1][index]), buf_size );
        index += buf_size;
    } while ( index <= length );
    write(1, "\n", 1);
    return 0;
}
