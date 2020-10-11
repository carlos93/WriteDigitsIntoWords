#include "Utils.h"

std::vector<std::string> SplitString(std::string const& phrase, std::string const& delimiter /*= " "*/)
{
    std::vector<std::string> res = {};

    size_t pos = 0;
    std::string token;
    std::string s = phrase;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        res.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    res.push_back(s);
    return res;
}
