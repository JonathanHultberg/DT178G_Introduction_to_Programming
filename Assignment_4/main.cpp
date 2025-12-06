//Jonathan Hultberg
//Datum: 241212
//Kurs: DT178G
//Laboration 4

#include "readFormat.h"
#include "copyToVec.h"
#include "sortByVal.h"
#include "print.h"
#include <iostream>
#include <algorithm>

int main()
{
    std::ifstream inFile;

    std::map<std::string, int> wordCount;
    std::vector<std::pair<std::string, int>> countWordPair;

    inFile.open("hitchhikersguide.txt");
    

    if(!inFile.is_open())
    {
        std::cout << "in filen kunde ej öppans" << std::endl;
        inFile.close();
        return 0;
    }


    readFormat(inFile,wordCount);

    copyToVec(wordCount,countWordPair);

    std::sort(countWordPair.begin(),countWordPair.end(),sortByVal);
    
    print(countWordPair);
    

    inFile.close();
    return 0;
}