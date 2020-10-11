#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "WordTransformer.h"

int main(int argc, char* argv[])
{
    if (argc < 1)
    {
        std::cout << "Error: Number of arguments incorrect, it should be > 1" << std::endl;
        return 1;
    }

    std::vector<std::string> words;
    for (int i = 1; i < argc; i++)
    {
        std::string wordToProcess = argv[i];

        std::cout << wordToProcess << " ";
        words.push_back(wordToProcess);
    }

    std::cout << std::endl;

    WordTransformer transformer = WordTransformer(std::move(words));
    std::string res = transformer.StartProcessingText();
    std::cout << res << std::endl;
    return 0;
}
