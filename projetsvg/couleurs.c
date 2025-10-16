// couleurs hex
#ifndef COULEURS_C
#define COULEURS_C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "couleurs.h"

int is_hex_char(char c) {
    return ( (c >= '0' && c <= '9') ||
             (c >= 'a' && c <= 'f') ||
             (c >= 'A' && c <= 'F') );
}

// code hex
void normalizeHexColor(const char *input, char *output, size_t size) {
    if (!input || !output) return;
    if (input[0] == '#' && strlen(input) == 4 &&
        is_hex_char(input[1]) && is_hex_char(input[2]) && is_hex_char(input[3])) {
        snprintf(output, size, "#%c%c%c%c%c%c",
                 input[1], input[1],
                 input[2], input[2],
                 input[3], input[3]);
    } else {
        strncpy(output, input, size - 1);
        output[size - 1] = '\0';
    }
}
#endif