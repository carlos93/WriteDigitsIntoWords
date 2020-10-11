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
    // Using int because of max number in exercise is 999.999.999
    std::optional<int> currentValue;
    std::optional<int> groupValue;
    bool hasGroupValue = false;
    bool hasCurrentValue = false;

    bool numberStarted = false;

    std::stringstream ss;
    for (size_t i = 0; i < _words.size(); i++)
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

            if (groupValue.has_value())
                currentValue = std::make_optional(currentValue.value_or(0) + groupValue.value());

            // Flush number if found before
            if (currentValue.has_value())
                AppendWord(ss, std::to_string(currentValue.value()));

            groupValue.reset();
            currentValue.reset();

            AppendWord(ss, str);
            continue;
        }

        // Figure found
        if (figure.has_value())
        {
            groupValue = std::make_optional(groupValue.value_or(0) + figure.value());
            numberStarted = true;
        }

        // Modify figure value
        if (modifier.has_value())
        {
            bool mult = modifier.value().second == ModifiersType::TYPE_MULTIPLIER ? true : false;

            // Modifiers groups closings, thousand, million and billion
            if (modifier.value().first == 1000 || modifier.value().first == 1000000 || modifier.value().first == 1000000000)
            {
                int val = currentValue.value_or(0) + (mult ? groupValue.value_or(0) * modifier.value().first : groupValue.value_or(0) + modifier.value().first);
                currentValue = std::make_optional(val);
                groupValue.reset();
            }
            else
            {
                int val = (mult ? groupValue.value_or(0) * modifier.value().first : groupValue.value_or(0) + modifier.value().first);
                groupValue = std::make_optional(val);
            }
        }

        std::cout << currentValue.value_or(0) << " " << groupValue.value_or(0) << std::endl;
    }

    if (groupValue.has_value())
        currentValue = std::make_optional(currentValue.value_or(0) + groupValue.value());

    if (currentValue.has_value())
        AppendWord(ss, std::to_string(currentValue.value()));

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
