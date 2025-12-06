#include "readFormat.h"

void readFormat(std::ifstream& inFile, std::map<std::string, int>& wordCount)
{
    std::string word;
    while (inFile>>word)
    {
        std::transform(word.begin(), word.end(), word.begin(), tolower);
        while(!word.empty() && !isalpha(word[0]))
        {
            word.erase(0,1);
        }

        while(!word.empty() && !isalpha(word[word.length()-1]))
        {
            word.erase(word.length()-1,1);
        }

        if(!word.empty())
        {
            wordCount[word]++;
        }
    }
}