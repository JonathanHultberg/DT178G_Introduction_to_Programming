#include "isSorted.h"

bool isSorted(std::ifstream& inFile)
{

int prev, curr;

inFile>>prev;

while((inFile>>curr))
{
    if(curr<prev)
    {
        return false;
    }

    prev=curr;
}

inFile.clear();
inFile.seekg(0);
return true;
}