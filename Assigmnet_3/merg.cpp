#include "merg.h"

void merg(std::ifstream& inFile1,std::ifstream& inFile2, std::ofstream& outFile)
{
    int curr1, curr2;

    inFile1 >> curr1;
    inFile2 >> curr2;

    while(!inFile1.eof() && !inFile2.eof())
    {
        if(curr1<curr2)
        {
            outFile << curr1 << " ";
            inFile1 >> curr1;
        }
        else
        {
            outFile << curr2 << " ";
            inFile2 >> curr2;
        }
    }

    while(!inFile1.eof())
    {
        outFile << curr1 << " ";
        inFile1 >> curr1;
    }

    while(!inFile2.eof())
    {
        outFile << curr2 << " ";
        inFile2 >> curr2;
    }
}