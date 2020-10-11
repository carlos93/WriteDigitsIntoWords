#include "pch.h"
#include "../WriteDigitsIntoWords/WordTransformer.h"
#include "../WriteDigitsIntoWords/Utils.h"

TEST(BasicTests, OneDigit)
{
    WordTransformer transformer = WordTransformer();
    StrVector words;
    std::string phrase = "";
    std::string correctPhrase = "";
    std::string finalText = "";

    phrase = "ZerO";
    correctPhrase = "0";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "One";
    correctPhrase = "1";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "TWO";
    correctPhrase = "2";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "three";
    correctPhrase = "3";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "FoUr";
    correctPhrase = "4";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "fiVE";
    correctPhrase = "5";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "six ";
    correctPhrase = "6";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "  seven ";
    correctPhrase = "7";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = " eight  ";
    correctPhrase = "8";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = " NINE  ";
    correctPhrase = "9";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);
}

TEST(BasicTests, TwoDigit)
{
    WordTransformer transformer = WordTransformer();
    StrVector words;
    std::string phrase = "";
    std::string correctPhrase = "";
    std::string finalText = "";

    phrase = "TEN ";
    correctPhrase = "10";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "ELEVEN";
    correctPhrase = "11";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = " TWelVE ";
    correctPhrase = "12";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "Thirteen";
    correctPhrase = "13";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "FourTEEN";
    correctPhrase = "14";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "  FIFTEEN";
    correctPhrase = "15";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "  sixteen ";
    correctPhrase = "16";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "SeVeNteEN";
    correctPhrase = "17";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "Eighteen";
    correctPhrase = "18";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "Nineteen";
    correctPhrase = "19";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "Twenty";
    correctPhrase = "20";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "Sixty   six ";
    correctPhrase = "66";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "  Ninety One ";
    correctPhrase = "91";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);
}


TEST(BasicTests, ThreeDigits)
{
    WordTransformer transformer = WordTransformer();
    StrVector words;
    std::string phrase = "";
    std::string correctPhrase = "";
    std::string finalText = "";

    phrase = "one hundred and one";
    correctPhrase = "101";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "two hundred sixty six";
    correctPhrase = "266";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "eight hundred";
    correctPhrase = "800";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);

    phrase = "six hundred and forty";
    correctPhrase = "640";
    words = SplitString(phrase);
    transformer.LoadPhrase(std::move(words));
    finalText = transformer.StartProcessingText();
    transformer.ClearWords();
    EXPECT_TRUE(finalText == correctPhrase);
}
