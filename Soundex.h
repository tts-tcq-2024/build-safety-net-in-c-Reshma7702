#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };
    c = toupper(c);
    return (c >= 'A' && c <= 'Z') ? soundexTable[c - 'A'] : '0';
}

void initializeSoundex(char *soundex, char firstCharacter) {
    soundex[0] = toupper(firstCharacter);
    memset(soundex + 1, '0', 3);
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
