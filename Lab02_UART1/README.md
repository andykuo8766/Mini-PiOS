Lab 2 - UART1, Auxilary mini UART
==========================

Raspberry Pi 3B+ 
CPU : BCM2837B0 64-bit quad-core ARM Cortex-A53

If you want to do this Lab.
You need know how to design in BCM2837 Peripherals first.
[BCM2837-Broadcom Peripherals](https://cs140e.sergio.bz/docs/BCM2837-ARM-Peripherals.pdf)


uart.c uart.h
==========================
```uart_init()``` initializes the device and maps it to the GPIO ports.

```uart_send(c)``` sends a character over the serial line.

```uart_getc()``` receives a character. The carrige return character (13) will be converted into a newline character (10).

```uart_puts(s)``` prints out a string. On newline, a carrige return character will also be sent (13 + 10).



How to run
==========================
```sh
$ make
$ make run
```

How to clean
==========================
```sh
$ make clean
```