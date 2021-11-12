Lab 3 - Mailboxes
==========================

Raspberry Pi Firmware
==========================
Note that the firmware for the Videocore is closed source, so there is no source code for it available in this repository. The Code section contains precompiled binaries only.

Mailboxes
==========================
Mailboxes are the primary means of communication between the ARM and the VideoCore firmware running on the GPU.


You need a mailbox before you can use UART0.
Use this to query the board serial number and output it to UART1.

> NOTE: qemu does not redirect UART1 to terminal by default, only UART0, so you have to use -serial null -serial stdio.

The mailbox interface. First we fill up the message in mbox array, then we call ```mbox_call(ch)``` to pass it to the GPU, specifying the mailbox channel. In this example we have used the property channel, which requires the message to be formatted as:

    0. size of the message in bytes, (x+1)*4
    1. MBOX_REQUEST magic value, indicates request message
    2-x. tags
    x+1. MBOX_TAG_LAST magic value, indicates no more tags

Where each tag looks like:

     n+0. tag identifier
     n+1. value buffer size in bytes
     n+2. must be zero
     n+3. optional value buffer


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

References
==========================
https://github.com/raspberrypi/firmware/wiki/Accessing-mailboxes
https://jsandler18.github.io/extra/mailbox.html
https://blog.csdn.net/suz_cheney/article/details/86027172
https://grasslab.github.io/osdi/en/hardware/mailbox.html#mailbox