#pragma once

#include <vector>
#include <string>

namespace Core
{
    inline std::vector<std::string>  Explode(const std::string& str, const char& ch);
}

namespace Core
{
    inline std::vector<std::string> Explode(const std::string& str, const char& ch)
    {
        std::string next;
        std::vector<std::string> result;

        // For each character in the string
        for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
        {
            // If we've hit the terminal character
            if (*it == ch)
            {
                // If we have some characters accumulated
                if (!next.empty())
                {
                    // Add them to the result vector
                    result.push_back(next);
                    next.clear();
                }
            } else
            {
                // Accumulate the next character into the sequence
                next += *it;
            }
        }
        if (!next.empty())
            result.push_back(next);
        return result;
    }
}
