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
    int currentValue = 0;
    int groupValue = 0;
    int totalValue = 0;

    bool numberStarted = false;

    std::stringstream ss;
    for (int i = 0; i < _words.size(); i++)
    {
        std::string str = _words.at(i);

        // Skip empty words
        if (str == "")
            continue;

        std::optional<int> figure = TryConvertWord(str);
        std::optional<std::pair<int, ModifiersType>> modifier;

        // Check if its a modifier
        if (!figure.has_value())
            modifier = TryConvertModifier(str);

        // Normal word found
        if ((!modifier.has_value() && !figure.has_value()) || (!numberStarted && str == "and"))
        {
            numberStarted = false;

            if (groupValue > 0)
            {
                currentValue += groupValue;
            }

            // Flush number if found before
            if (currentValue > 0)
            {
                AppendWord(ss, std::to_string(currentValue));
            }

            groupValue = 0;
            currentValue = 0;

            AppendWord(ss, str);
            continue;
        }

        // Figure found
        if (figure.has_value())
        {
            groupValue += figure.value();
            numberStarted = true;
        }

        // Modify figure value
        if (modifier.has_value())
        {
            bool mult = modifier.value().second == ModifiersType::TYPE_MULTIPLIER ? true : false;

            if (modifier.value().first == 1000 || modifier.value().first == 1000000 || modifier.value().first == 1000000000)
            {
                currentValue += mult ? groupValue * modifier.value().first : groupValue + modifier.value().first;
                groupValue = 0;
            }
            else
            {
                groupValue = mult ? groupValue * modifier.value().first : groupValue + modifier.value().first;
            }
        }

        //std::cout << currentValue << " " << groupValue << std::endl;
    }

    if (groupValue > 0)
    {
        currentValue += groupValue;
    }

    if (currentValue > 0)
    {
        AppendWord(ss, std::to_string(currentValue));
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
