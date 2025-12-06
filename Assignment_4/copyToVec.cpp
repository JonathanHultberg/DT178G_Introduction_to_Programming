#include "copyToVec.h"

void copyToVec(std::map<std::string, int>& wordCount, std::vector<std::pair<std::string, int>>& vecPair)
{
    std::copy(wordCount.begin(),wordCount.end(),std::back_inserter(vecPair));
    
}