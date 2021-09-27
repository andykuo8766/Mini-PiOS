#include "uart.h"
#include "mbox.h"
#include "rand.h"
#include "delays.h"
#include "power.h"
#include "lfb.h"

void main()
{
    // set up serial console
    //uart_init();

/*Lab5
    // set up random number generator
    rand_init();  
    
    uart_puts("Here goes a random number: ");
    uart_hex(rand(0,4294967295));
    uart_puts("\n");
*/
/*Lab6
    uart_puts("Waiting 1000000 CPU cycles (ARM CPU): ");
    wait_cycles(1000000);
    uart_puts("OK\n");

    uart_puts("Waiting 1000000 microsec (ARM CPU): ");
    wait_msec(1000000);
    uart_puts("OK\n");

    uart_puts("Waiting 1000000 microsec (BCM System Timer): ");
    if(get_system_timer()==0) {
        uart_puts("Not available\n");
    } else {
        wait_msec_st(1000000);
        uart_puts("OK\n");
    }
*/
/*Lab3
    // get the board's unique serial number with a mailbox call
    mbox[0] = 8*4;                  // length of the message
    mbox[1] = MBOX_REQUEST;         // this is a request message
    
    mbox[2] = MBOX_TAG_GETSERIAL;   // get serial number command
    mbox[3] = 8;                    // buffer size
    mbox[4] = 8;
    mbox[5] = 0;                    // clear output buffer
    mbox[6] = 0;

    mbox[7] = MBOX_TAG_LAST;

    // send the message to the GPU and receive answer
    if (mbox_call(MBOX_CH_PROP)) {
        uart_puts("My serial number is: ");
        uart_hex(mbox[6]);
        uart_hex(mbox[5]);
        uart_puts("\n");
    } else {
        uart_puts("Unable to query serial!\n");
    }
*/

/*Lab7
    while(1) {
        uart_puts(" 1 - power off\n 2 - reset\nChoose one: ");
        char c=uart_getc();
        uart_send(c);
        uart_puts("\n\n");
        if(c=='1') power_off();
        if(c=='2') reset();
    }
*/
//Lab9

    // set up serial console and linear frame buffer
    uart_init();
    lfb_init();

    // display an ASCII string on screen with PSF
    lfb_print(80, 80, "Hello World!");

    // display a UTF-8 string on screen with SSFN
    //lfb_proprint(80, 120, "Hello 多种语言 Многоязычный többnyelvű World!");


    // echo everything back
    while(1) {
        uart_send(uart_getc());
    }



}
