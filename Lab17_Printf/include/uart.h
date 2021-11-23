void uart_init();
void uart_send(unsigned int c);
char uart_getc();
void printf(char *fmt, ...);
void uart_puts(char *s);
void uart_hex(unsigned int d);
void uart_dump(void *ptr);