#include <gtest/gtest.h>
#include "Soundex.h"

// Append 3 zeros if result contains less than 3 digits
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
    // AAA
    char soundex[5];
    generateSoundex("BX", soundex);
    ASSERT_STREQ(soundex, "B200");
}

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
    // AAA
    char soundex[5];
    generateSoundex("B2DFGh", soundex);
    ASSERT_STREQ(soundex, "B231");
}

// Test case to check special character
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
    // AAA
    char soundex[5];
    generateSoundex("B#", soundex);
    ASSERT_STREQ(soundex, "B000");
}

// Replace all adjacent same digits with one digit
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_4) {
    // AAA
    char soundex[5];
    generateSoundex("Bgfp", soundex);
    ASSERT_STREQ(soundex, "B210");
}

// Two letters with the same number separated by 'h', 'w' or 'y' are coded as a single number
TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits_5) {
    // AAA
    char soundex[5];
    generateSoundex("DSjZ", soundex);
    ASSERT_STREQ(soundex, "D200");
}
