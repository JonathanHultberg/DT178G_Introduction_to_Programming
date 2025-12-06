//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#include "contact.h"
#include "MemoryManager.h"
#include "AddContact.h"
#include "Utility.h"
#include "ContactViewer.h"

int main()
{
    std::fstream memory;
    std::vector<Contact> runTimeMem;
    int alt;
    bool running = true;

    //Hjälp från: cplusplus.com
    memory.open("memory.txt",std::ios::in|std::ios::out|std::ios::app);
    //Slut hjälp

    if(!memory.is_open())
    {
        std::cout << "Minnesfilen kunde ej öppnas, programmet avslutas" << std::endl;
        memory.close();
        return 0;
    }

    readFromMem(memory,runTimeMem);

    emptyTerm();

    do
    {

        std::cout << "Meny - Skriv in ett av alternativen (1-4) avsluta med Enter:\n"
                  << "------------------------------------------------------------\n"
                  << "1. Lägg till kontakt\n"
                  << "2. Visa kontakter\n"
                  << "3. Sök kontakt \n"
                  << "4. Återställ från säkerhetskopia\n"
                  << "5. Avsluta programmet\n"
                  << "Alternativ: ";
        std::cin >> alt;
        std::cin.ignore();

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Ogiltig inmatning! Skriv in en siffra mellan 1 och 4.\n";
        }

        switch(alt)
        {
            case 1:
                addContact(memory,runTimeMem);
                emptyTerm();
                break;
            case 2:
                viewContacts(runTimeMem,memory);
                emptyTerm();
                break;
            case 3:
                search(runTimeMem,memory);
                emptyTerm();
                break;
            case 4:
                recoverBackUp(runTimeMem,memory);
                emptyTerm();
                break;
            case 5:
                running = false;
                break;
            default:
                emptyTerm();
                std::cout << "Ogiltig inmatning! Skriv in en siffra mellan 1 och 4.\n";
                break;
        }
    } while (running);
    
    
    emptyTerm();

    std::cout << "Programmet avslutas" << std::endl;

    memory.close();
    return 0;
}