#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "Utils.h"
#include "WordTransformer.h"

void ProcessInput(int argc, char* argv[], std::vector<std::string>& words)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string wordToProcess = argv[i];
            words.push_back(wordToProcess);
        }
    }
    else
    {
        std::string phrase = "";
        std::getline(std::cin, phrase);

        words = SplitString(phrase);
    }
}

int main(int argc, char* argv[])
{
    std::vector<std::string> words;

    ProcessInput(argc, argv, words);

    WordTransformer transformer = WordTransformer(std::move(words));
    std::string res = transformer.StartProcessingText();
    std::cout << res << std::endl;
    return 0;
}
