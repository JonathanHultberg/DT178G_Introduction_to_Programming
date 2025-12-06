#include "print.h"

void print(const std::vector<std::pair<std::string, int>>& countWordPair)
{
    unsigned int n;
    std::cout << "Programmet räknar förekomsten av unika ord i hitchhikersguide.txt" 
              << " sorterat mest förekommande till minst\nAnge antalet ord du vill ska presenteras: ";

    std::cin >> n;

    if(countWordPair.size()<n)
    {
        n = countWordPair.size();
    }

    const int widthWord = 10; 
    const int widthCount = 10;

    std::cout << "\n\nDet " << n << " mest förekommande orden är:"
              << "\n\nAntal     Ord\n-------------" << std::endl;


    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << std::left << std::setw(widthCount) << countWordPair[i].second
                  << std::left << std::setw(widthWord) << countWordPair[i].first << '\n';
    }
}