#include <stdio.h>
#include <stdint.h>

void
print_start_debug(void *mæin, void *fun0, void *fun1, void *fun2, void *fun3,
    void *fun4, void *incr€dible_function)
{
    printf("Debug]\n");
    printf("Main ptr: %p\n", mæin);
    printf("Fun0 ptr: %p\n", fun0);
    printf("Fun1 ptr: %p\n", fun1);
    printf("Fun2: %p\n", fun2);
    printf("Fun3: %p\n", fun3);
    printf("Fun4: %p\n", fun4);
    printf("Incredible_function pr: %p\n", incr€dible_function);
    printf("____________\n___________\n");
}

//
void
set_registers(uint64_t first, uint64_t second, uint64_t third, uint64_t fourth,
    uint64_t fifth, uint64_t sixth)
{
    printf("Registers set to:\n");
    printf("First: 0x%lx\n", first);
    printf("Second: 0x%lx\n", second);
    printf("Third: 0x%lx\n", third);
    printf("Fourth: 0x%lx\n", fourth);
    printf("Fifth: 0x%lx\n", fifth);
    printf("Sixth: 0x%lx\n", sixth);
    printf("_____________\n\n");
    return;
}

int
incredible_function(uint64_t f, uint64_t s,
    uint64_t t, uint64_t fo)
{
    printf("___\n");
    if (f != 0)
        printf("First: 0x%lx\n", f);
    if (s != 0)
        printf("Second: 0x%lx\n", s);
    if (t != 0)
        printf("Third: 0x%lx\n", t);
    if (fo != 0)
        printf("Fourth: 0x%lu\n", fo);
    printf("___\n");
    return 0;
}

int main(void)
{
    int (*fun4) (uint64_t, uint64_t, uint64_t, uint64_t) = incredible_function;
    int (*fun3) (uint64_t, uint64_t, uint64_t) = incredible_function;
    int (*fun2) (uint64_t, uint64_t) = incredible_function;
    int (*fun1) (uint64_t) = incredible_function;
    int (*fun0) () = incredible_function;

    print_start_debug(main, fun0, fun1, fun2, fun3, fun4, incredible_function);
    //set garbage data to registers
    set_registers((uint64_t) &main, &main, &main, &main, &main, &main);
    //set valid data to registers
    set_registers(0, 0x42, 0, 0, 0, 0);
    //should only print 42 in second
    fun0();
    //should only print 21 42
    set_registers(0, 0, 0, 0, 0, 0);
    fun2(0x21, 0x42);
    //should only print 21 42 84
    set_registers(0, 0, 0, 0, 0, 0);
    fun3(0x21, 0x42, 0x84);
    return 0;
}
