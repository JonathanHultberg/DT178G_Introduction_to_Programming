#include "sortByVal.h"

bool sortByVal(const std::pair<std::string, int>& a,const std::pair<std::string, int>& b)
{
    return a.second > b.second;
}