//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#include "MemoryManager.h"

// Läser in data från minnesfilen till runtime-vektorn och sorterar kontakterna.
// Parametrar:
// - memory: En fildataström som används för att läsa kontaktdata från filen.
// - runTimeMem: En vektor som innehåller kontaktinformation i form av `contact`-objekt.
// Returvärde: Inget.
void readFromMem(std::fstream& memory, std::vector<Contact>& runTimeMem)
{
    Contact fromMem;

    while(std::getline(memory,fromMem.firstName,';') && std::getline(memory,fromMem.lastName,';') && 
          std::getline(memory,fromMem.address,';') && std::getline(memory,fromMem.postalCode,';') && 
          std::getline(memory,fromMem.city,';') && std::getline(memory,fromMem.mailAddress,';') && 
          std::getline(memory,fromMem.phoneNumber,';') && std::getline(memory,fromMem.birthDay))
    {
        runTimeMem.push_back(fromMem);
    }

    //Hjälp från: geeksforgeeks.org
    std::sort(runTimeMem.begin(),runTimeMem.end(), [](const Contact& a, const Contact& b){
        return a.lastName < b.lastName;
    });
    //Slut hjälp!

    memory.clear();
}

// Återställer runtime-minnet och minnesfilen från en säkerhetskopia, om den finns.
// Parametrar:
// - runTimeMem: En vektor som innehåller kontaktinformation i form av `contact`-objekt.
// - memory: En fildataström som används för att skriva återställda data till minnesfilen.
// Returvärde: Inget.
void recoverBackUp(std::vector<Contact>& runTimeMem, std::fstream& memory) 
{   //Kontroller
    std::ifstream backUp("backUp.txt");
    if (!backUp.is_open()) 
    {
        std::cout << "Backupfilen kunde ej öppnas! Återställning av minnet misslyckades." << std::endl;
        return;
    }

    memory.close(); 
    memory.open("memory.txt", std::ios::out | std::ios::trunc);
    if (!memory.is_open()) 
    {
        std::cout << "Minnesfilen kunde ej öppnas! Återställning misslyckades." << std::endl;
        return;
    }

    //Återställning av minne och runTimeMem från säkerhetskopia
    std::string memLine;
    while (std::getline(backUp, memLine)) 
    {
        memory << memLine << "\n";
    }
    backUp.close(); 

    memory.close(); 
    memory.open("memory.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!memory.is_open()) 
    {
        std::cout << "Minnesfilen kunde ej öppnas efter ändring!" << std::endl;
        return;
    }

    
    if (std::remove("backUp.txt") != 0) 
    {
        std::cout << "Backupfilen kunde ej tas bort." << std::endl;
    }
    else 
    {
        std::cout << "Backupfilen är borttagen." << std::endl;
    }

    
    runTimeMem.clear();
    readFromMem(memory, runTimeMem);
    std::cout << "Återställning har genomförts!" << std::endl;
}
