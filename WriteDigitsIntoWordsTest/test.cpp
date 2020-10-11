#include "pch.h"
#include "../WriteDigitsIntoWords/WordTransformer.h"
#include "../WriteDigitsIntoWords/Utils.h"

TEST(PhraseTests, Test1) {

    StrVector words;
    std::string phrase = "I have two thousand three hundred and sixty six apples and twenty five oranges";
    std::string correctPhrase = "I have 2366 apples and 25 oranges";

    words = SplitString(phrase);

    WordTransformer transformer = WordTransformer(std::move(words));
    std::string finalText = transformer.StartProcessingText();

    EXPECT_TRUE(finalText == correctPhrase);
}

TEST(PhraseTests, Test2) {

    StrVector words;
    std::string phrase = "Would you like to buy eight hundred and thirty six of this and pay me one million and one dollars?";
    std::string correctPhrase = "Would you like to buy 836 of this and pay me 1000001 dollars?";

    words = SplitString(phrase);

    WordTransformer transformer = WordTransformer(std::move(words));
    std::string finalText = transformer.StartProcessingText();

    EXPECT_TRUE(finalText == correctPhrase);
}
//
//TEST(PhraseTests, Test3) {
//
//    StrVector words;
//    std::string phrase = "Would you like to buy eight hundred and thirty six of this and pay me one billion three thousand one hundred twenty million and one dollars?";
//    std::string correctPhrase = "Would you like to buy 836 of this and pay me 1000001 dollars?";
//
//    words = SplitString(phrase);
//
//    WordTransformer transformer = WordTransformer(std::move(words));
//    std::string finalText = transformer.StartProcessingText();
//
//    EXPECT_TRUE(finalText == correctPhrase);
//}
