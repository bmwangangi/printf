#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

unsigned int betty_base_length(unsigned int num, int base);
char *betty_reverse_string(char *string);
void betty_write_to_stdout(char *str);
 char *betty_memcpy(char *destination, char *source,int betty_hex_check(int num, char x);
int betty_hex_check(int num, char x);
int betty_puts(char *string);
int betty_putchar(char x);


#endif
