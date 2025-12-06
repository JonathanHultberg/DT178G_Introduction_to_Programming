//Jonathan Hultberg
//Datum: 241125
//Kurs: DT178G
//Laboration 3

#include "isSorted.h"
#include "val.h"
#include "which.h"
#include "merg.h"

int main()
{
    bool statSort1, statSort2;
    std::ifstream inFile1,inFile2, valOut;
    inFile1.open("A");
    inFile2.open("B");

    std::ofstream outFile;
    outFile.open("out");


    if(!val(inFile1))
    {
        std::cout << "Felet ovan uppstod för inFile1" << std::endl;
        inFile1.close();
        inFile2.close();
        outFile.close();
        return 0;
    }
    
    if(!val(inFile2))
    {
        std::cout << "Felet ovan uppstod för inFile2" << std::endl;
        inFile1.close();
        inFile2.close();
        outFile.close();
        return 0;
    }

    if(!outFile.is_open())
    {
        std::cout << "Felet outFile gick ej att öppna" << std::endl;
        inFile1.close();
        inFile2.close();
        outFile.close();
        return 0;
    }

    statSort1 = isSorted(inFile1);
    statSort2 = isSorted(inFile2);

    if(!statSort1 || !statSort2)
    {
        which(statSort1, statSort2);
        std::cout << "Programmet avslutas" << std::endl;
        inFile1.close();
        inFile2.close();
        outFile.close();
        return 0;
    }
    
    std::cout << "Båda filerna är sorterade och klara för merge!" << std::endl;

    merg(inFile1, inFile2, outFile);

    inFile1.close();
    inFile2.close();
    outFile.close();

    valOut.open("out");

    if(!val(valOut))
    {
        std::cout << "Felet ovan uppstod vid validering av utfilen" << std::endl;
        valOut.close();
        return 0;
    }

    if(isSorted(valOut))
    {
        std::cout << "Merg funka som det ska!" << std::endl;
    }
    else
    {
        std::cout << "Merg har INTE fungerat" << std::endl;
    }


    std::cout << "Programmmet avslutas!" << std::endl;

    return 0;
}