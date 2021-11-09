Lab 0 - Bare Minimum
==========================
Just test our toolchain. The resulting kernel8.img should boot on Raspberry Pi, and stop the CPU cores in an infinite loop. You can check that by running

Assembly
==========================
When the control is passed to kernel8.img, the environment is not ready for C. Therefore we must implement a small preambule in Assembly.
> CPU has 4 cores. All of them are running the same infinite loop for now.


Makefile
==========================
Our Makefile is very simple. We compile start.S, as this is our only source. Then in linker phase we link it using the linker.ld script. Finaly we convert the resulting elf executable into a raw image.

Linker script
==========================
Not surpisingly simple too. We just set the base address where our kernel8.img will be loaded, and we put the only section we have there.
> For AArch64 the load address is 0x80000, and not 0x8000 as with AArch32.



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