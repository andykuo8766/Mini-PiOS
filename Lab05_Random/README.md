Lab 5 - Hardware Random Number Generator
==========================
Let's query a number from the (undocumented) hardware random number generator. You can use this to implement a simple, but accurate dice throw in any game. It is important as without hardware support you can only generate pseudo-random numbers.

Rand.c Rand.h
==========================
```rand_init()``` initializes the hardware.

```rand(min,max)``` returns a random number between min and max.

https://www.raspberrypi.org/forums/viewtopic.php?t=196015
https://github.com/raspberrypi/linux/blob/204050d0eafb565b68abf512710036c10ef1bd23/drivers/char/hw_random/bcm2835-rng.c



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
