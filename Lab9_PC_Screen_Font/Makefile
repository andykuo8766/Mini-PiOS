SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles

all: clean kernel8.img

start.o: start.S
	aarch64-linux-gnu-gcc $(CFLAGS) -c start.S -o start.o

%.o: %.c
	aarch64-linux-gnu-gcc $(CFLAGS) -c $< -o $@

font_psf.o: font.psf
	aarch64-linux-gnu-ld -r -b binary -o font_psf.o font.psf

font_sfn.o: font.sfn
	aarch64-linux-gnu-ld -r -b binary -o font_sfn.o font.sfn

kernel8.img: start.o font_psf.o font_sfn.o $(OBJS)
	aarch64-linux-gnu-ld -nostdlib -nostartfiles start.o font_psf.o font_sfn.o $(OBJS) -T link.ld -o kernel8.elf
	aarch64-linux-gnu-objcopy -O binary kernel8.elf kernel8.img

clean:
	rm kernel8.elf *.o >/dev/null 2>/dev/null || true

run:
	qemu-system-aarch64 -M raspi3 -kernel kernel8.img -serial null -serial stdio