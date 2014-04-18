#include "Soundex.h"
#include "gmock/gmock.h"

using namespace testing;

class SoundexEncoding : public Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   ASSERT_EQ(soundex.Encode("A"), "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    ASSERT_EQ(soundex.Encode("I"), "I000");
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
    EXPECT_EQ(soundex.Encode("Ab"), "A100");
    EXPECT_EQ(soundex.Encode("Ac"), "A200");
    EXPECT_EQ(soundex.Encode("Ad"), "A300");
    EXPECT_EQ(soundex.Encode("Al"), "A400");
    EXPECT_EQ(soundex.Encode("Am"), "A500");
    ASSERT_EQ(soundex.Encode("Ar"), "A600");
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics){
    ASSERT_EQ(soundex.Encode("A#"), "A000");
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits){
    ASSERT_EQ(soundex.Encode("Acdl"), "A234");
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
    ASSERT_EQ(soundex.Encode("Dcdlb").length(), 4u);
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters){
    ASSERT_EQ(soundex.Encode("Baeiouhycdl"), "B234");
}

TEST_F(SoundexEncoding,DISABLED_CombinesDuplicateEncodings){
    ASSERT_EQ(soundex.Encode("b"), soundex.Encode("f"));
    ASSERT_EQ(soundex.Encode("c"), soundex.Encode("g"));
    ASSERT_EQ(soundex.Encode("d"), soundex.Encode("t"));

    ASSERT_EQ(soundex.Encode("Abfcgdt"), soundex.Encode("A123"));
}

