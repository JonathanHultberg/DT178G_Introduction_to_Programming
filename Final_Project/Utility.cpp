//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#include "Utility.h"

// Rensar terminalfönstret genom att skriva ut ett antal tomma rader.
// Parametrar: Inga.
// Returvärde: Inget.
void emptyTerm()
{
    for (int i=0; i<100 ; i++)
    {
        std::cout << "\n" << std::endl;
    }

}