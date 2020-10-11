#include <sstream>
#include <algorithm>
#include "WordTransformer.h"
#include "Utils.h"

WordTransformer::WordTransformer(StrVector&& words)
{
    _words = words;
}

void WordTransformer::ClearWords()
{
    _words.clear();
}

void WordTransformer::LoadPhrase(StrVector&& words)
{
    _words = words;
}

std::stringstream& AppendWord(std::stringstream& ss, std::string const& word)
{
    if (!ss.str().empty())
        ss << " " << word;
    else
        ss << word;

    return ss;
}

std::string WordTransformer::StartProcessingText()
{
    bool numberStarted = false;
    bool lastWasFigure = false;
    bool lastWasModifier = false;
    bool groupStarted = false;
    int figureValue = 0;
    int figureGroupValue = 0;
    int totalNumber = 0;
    int tempSum = 0;
    std::stringstream ss;
    for (int i = 0; i < _words.size(); i++)
    {
        bool numberFinished = false;
        std::string str = _words.at(i);

        // Skip empty words
        if (str == "")
            continue;

        std::optional<int> figure = TryConvertWord(str);
        std::optional<std::pair<int, ModifiersType>> modifier;

        // Check if its a modifier
        if (!figure.has_value())
            modifier = TryConvertModifier(str);

        // Nothing found, ignoring
        if ((!modifier.has_value() && !figure.has_value()) || (!numberStarted && str == "and"))
        {
            if (numberStarted)
            {
                tempSum += figureValue;
                AppendWord(ss, std::to_string(tempSum));
            }
            figureValue = 0;
            figureGroupValue = 0;
            totalNumber = 0;
            tempSum = 0;
            numberStarted = false;
            groupStarted = false;

            AppendWord(ss, str);
            continue;
        }

        // Figure found
        if (figure.has_value())
        {
            if (lastWasFigure)
                figureValue += figure.value();
            else
                figureValue = figure.value();

            figureGroupValue = 0;
            lastWasFigure = true;
            lastWasModifier = false;
            numberStarted = true;
            groupStarted = true;
            std::cout << figureValue << " " << figureGroupValue << std::endl;
        }

        // Modify figure value
        if (modifier.has_value())
        {
            bool mult = modifier.value().second == ModifiersType::TYPE_MULTIPLIER ? true : false;
            //if (modifier.value().first != 1000000)
            {
                figureValue = mult ? figureValue * modifier.value().first : figureValue + modifier.value().first;
            }

            lastWasFigure = false;
            lastWasModifier = true;
            figureGroupValue += figureValue;
            std::cout << figureValue << " " << figureGroupValue << std::endl;
            //if (modifier.value().first == 1000000)
            //    groupStarted = false;
        }

        if (lastWasModifier)
            tempSum += figureGroupValue;

        if (i == _words.size() - 1)
            tempSum += figureValue;

        //std::cout << std::to_string(figureValue) << ": Total: " << std::to_string(totalNumber) << std::endl;
    }

    if (numberStarted)
    {
        totalNumber += figureValue;
        AppendWord(ss, std::to_string(totalNumber));
    }

    return ss.str();
}

std::optional<int> WordTransformer::TryConvertWord(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    auto itr = correlationTable.find(str);
    if (itr != correlationTable.end())
        return itr->second;

    return std::nullopt;
}

std::optional<std::pair<int, ModifiersType>> WordTransformer::TryConvertModifier(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    auto itr = modifiers.find(str);
    if (itr != modifiers.end())
        return itr->second;

    return std::nullopt;
}
