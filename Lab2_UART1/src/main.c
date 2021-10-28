#define Lab 2

#include "uart.h"

void main()
{
#if Lab == 1
    //Lab 1: Multicore C
    while(1);
#elif Lab == 2
    //Lab 2: UART1
    // set up serial console
    uart_init();
    
    // say hello
    uart_puts("Hello World!\n");
    
    // echo everything back
    while(1) {
        uart_send(uart_getc());
    }
#endif
}
