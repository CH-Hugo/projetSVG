// couleurs hex
#ifndef COULEURS_H
#define COULEURS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_hex_char(char c);
void normalizeHexColor(const char *input, char *output, size_t size);

#endif