#pragma once

#ifndef WORDTRANSFORMER_H
#define WORDTRANSFORMER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <optional>

typedef std::vector<std::string> StrVector;

enum class ModifiersType : int
{
    TYPE_MULTIPLIER = 0,
    TYPE_ADDITION   = 1
};

static std::unordered_map<std::string, int> correlationTable = {
    { "ZERO",       0},
    { "ONE",        1},
    { "TWO",        2},
    { "THREE",      3},
    { "FOUR",       4},
    { "FIVE",       5},
    { "SIX",        6},
    { "SEVEN",      7},
    { "EIGHT",      8},
    { "NINE",       9},
    { "TEN",        10},
    { "ELEVEN",     11},
    { "TWELVE",     12},
    { "THIRTEEN",   13},
    { "FOURTEEN",   14},
    { "FIFTEEN",    15},
    { "SIXTEEN",    16},
    { "SEVENTEEN",  17},
    { "EIGHTEEN",   18},
    { "NINETEEN",   19},
    { "TWENTY",     20},
    { "THIRTY",     30},
    { "FORTY",      40},
    { "FIFTY",      50},
    { "SIXTY",      60},
    { "SEVENTY",    70},
    { "EIGHTY",     80},
    { "NINETY",     90},
    { "AND",         0},
};

static std::unordered_map<std::string, std::pair<int, ModifiersType>> modifiers = {
    { "TEEN",       { 10, ModifiersType::TYPE_ADDITION } },
    { "HUNDRED",    { 100, ModifiersType::TYPE_MULTIPLIER} },
    { "THOUSAND",   { 1000, ModifiersType::TYPE_MULTIPLIER} },
    { "MILLION",    { 1000000, ModifiersType::TYPE_MULTIPLIER} },
    { "BILLION",    { 1000000000, ModifiersType::TYPE_MULTIPLIER} }
};

class WordTransformer
{
public:
    WordTransformer() = default;
    WordTransformer(StrVector&& words);
    ~WordTransformer() = default;

    std::string StartProcessingText();
    void ClearWords();
    void LoadPhrase(StrVector&& words);

private:
    std::optional<int> TryConvertWord(std::string str);
    std::optional<std::pair<int, ModifiersType>> TryConvertModifier(std::string str);

    StrVector _words;
};

#endif // WORDTRANSFORMER_H

