#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Table for soundex codes
static const char soundexTable[26] = {
    '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
};

// Function to get the soundex code for a character
char getSoundexCode(char c) {
    c = toupper(c);
    return (c >= 'A' && c <= 'Z') ? soundexTable[c - 'A'] : '0';
}

// Function to initialize the soundex array
void initializeSoundex(char *soundex, char firstCharacter) {
    soundex[0] = toupper(firstCharacter);
    memset(soundex + 1, '0', 3);
    soundex[4] = '\0';
}

// Function to check if a character's soundex code should be added
int shouldAddToSoundex(char code, const char *soundex, int sIndex) {
    return sIndex < 4 && code != '0' && code != soundex[sIndex - 1];
}

// Function to process a single character
void processCharacter(char code, char *soundex, int *sIndex) {
    if (shouldAddToSoundex(code, soundex, *sIndex)) {
        soundex[*sIndex] = code;
        (*sIndex)++;
    }
}

// Function to generate the soundex code for a given name
void generateSoundex(const char *name, char *soundex) {
    initializeSoundex(soundex, name[0]);
    int sIndex = 1;
    for (int i = 1; name[i] != '\0'; i++) {
        char code = getSoundexCode(name[i]);
        processCharacter(code, soundex, &sIndex);
    }
}

#endif // SOUNDEX_H
