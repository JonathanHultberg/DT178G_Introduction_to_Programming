//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#include "ContactViewer.h"

// Visar alla kontakter i listan och låter användaren välja en kontakt för att se detaljer eller återgå till huvudmenyn.
// Parametrar:
// - runTimeMem: En vektor som innehåller kontaktinformation i form av `contact`-objekt.
// - memory: En fildataström som används för att läsa/skriva kontaktdata till en fil.
// Returvärde: Inget.
void viewContacts(std::vector<Contact>& runTimeMem,std::fstream& memory)
{
    bool running = true;
    do
    {
        long unsigned int alt;
        
        emptyTerm();
        std::cout << "Kontaktlista\n------------" << std::endl;

        //Skriver ut kontakterna med modifierad index
        for (long unsigned int i = 0; i<runTimeMem.size();i++)
        {
            std::cout << i + 1 << " - " << runTimeMem[i].lastName << ", " << runTimeMem[i].firstName << "\n";
        }

        std::cout << "\n\nMata in siffran för kontakten du vill se fullständig information (1-" << runTimeMem.size()
                  << ") avsluta med Enter\nVill du gå tillbaka till huvudmenyn mata in 0\nAlternativ: ";
        std::cin >> alt;
        std::cin.ignore();

        //Kontrollerar att giltig inmatning har skett
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore();
        }
        else
        {
            if (alt == 0)
            {
                running = false;
            }
            if (alt >= 1 && alt <= runTimeMem.size())
            {
                alt -= 1; //Modifiering av index för att passa indexering i runTimeMemory
                openContact(alt,runTimeMem,memory);
            }
        }
    }while (running);

}


// Låter användaren söka efter en kontakt baserat på en sträng och visa matchande resultat.
// Parametrar:
// - runTimeMem: En vektor som innehåller kontaktinformation i form av `contact`-objekt.
// - memory: En fildataström som används för att läsa/skriva kontaktdata till en fil.
// Returvärde: Inget.
void search(std::vector<Contact>& runTimeMem, std::fstream& memory)
{
    long unsigned int alt, altOpen;
    bool running = true;
    std::string searchTerm;
    std::string strOfInfo;
    std::vector<long unsigned int> foundIndex;
   
    emptyTerm();

    do
    {   

        std::cout << "Skriv in en sökterm och tryck på Enter.\n"
                  << "För att återgå till huvudmenyn, lämna fältet tomt och tryck på Enter.\n"
                  << "(OBS! Om du endast trycker på mellanslag, räknas det som ett tomt fält.)\n"
                  << "Sökfält: ";

        std::getline(std::cin, searchTerm);
        
        //Avslutar sökningen om fältet lämnas tomt
        if(std::all_of(searchTerm.begin(), searchTerm.end(), isspace) || searchTerm.empty())
        {
            running = false;
        }
        
        if(!std::all_of(searchTerm.begin(), searchTerm.end(), isspace) && !searchTerm.empty())
        {   
            std::transform(searchTerm.begin(),searchTerm.end(),searchTerm.begin(),tolower);

            //Sökning genomförs
            for (long unsigned int i = 0; i<runTimeMem.size();i++)
            {
                strOfInfo = runTimeMem[i].firstName + " " + runTimeMem[i].lastName + " " + runTimeMem[i].address + " "
                          + runTimeMem[i].postalCode + " " + runTimeMem[i].city + " " + runTimeMem[i].mailAddress + " "
                          + runTimeMem[i].phoneNumber + " " + runTimeMem[i].birthDay;
                
                std::transform(strOfInfo.begin(),strOfInfo.end(),strOfInfo.begin(),tolower);

                //Hjälp från cplusplus.com
                if(strOfInfo.find(searchTerm) != std::string::npos)
                {
                    foundIndex.push_back(i);
                }
                //Slut hjälp
            }

            //Om sökningen gav träff pressenteras i en lista med modifierad index
            if(!foundIndex.empty())
            {
                bool inSearch = true;
                do
                {   
                    emptyTerm();
                    for (long unsigned int p = 0; p<foundIndex.size();p++)
                    {
                        std::cout << p + 1 << " - " << runTimeMem[foundIndex[p]].lastName << ", " << runTimeMem[foundIndex[p]].firstName << "\n";
                    }
                    
                    std::cout << "\n\nMata in siffran för kontakten du vill se fullständig information (1-" << foundIndex.size()
                              << ") avsluta med Enter\nVill du göra en ny sökning mata in 0\nAlternativ: ";

                    std::cin >> alt;
                    std::cin.ignore();
                    //Kontrollerar att giltig inmatning skett
                    if (std::cin.fail()) 
                    {
                        std::cin.clear();
                        std::cin.ignore();
                    }
                    else
                    {
                        //Ny sökning
                        if(alt==0)
                        {
                            inSearch = false;
                            foundIndex.clear();
                            emptyTerm();
                        }

                        //Öppnar vald kontakt
                        if (alt >= 1 && alt <= foundIndex.size())
                        {   emptyTerm();
                            altOpen = foundIndex[alt - 1]; 
                            openContact(altOpen, runTimeMem, memory);
                            foundIndex.clear();

                            //Ny sökning med samma temr, för att uppdatera eventuell ändring
                            for (long unsigned int i = 0; i<runTimeMem.size();i++)
                            {
                                strOfInfo = runTimeMem[i].firstName + " " + runTimeMem[i].lastName + " " + runTimeMem[i].address + " "
                                        + runTimeMem[i].postalCode + " " + runTimeMem[i].city + " " + runTimeMem[i].mailAddress + " "
                                        + runTimeMem[i].phoneNumber + " " + runTimeMem[i].birthDay;
                                
                                std::transform(strOfInfo.begin(),strOfInfo.end(),strOfInfo.begin(),tolower);
                            
                                if(strOfInfo.find(searchTerm) != std::string::npos)
                                {
                                    foundIndex.push_back(i);
                                }
                            }

                            emptyTerm();
                        }
                    }
                } while (inSearch);
            } 
            else 
            {
                emptyTerm();
                std::cout << "Sökningen gav inga träffar!\n\n" << std::endl;
            }
        }
    } while (running);
}

// Visar detaljerad information om en specifik kontakt och låter användaren välja att radera den.
// Parametrar:
// - alt: Index för kontakten som ska visas (modifieras för att passa vektorindexering).
// - runTimeMem: En vektor som innehåller kontaktinformation i form av `contact`-objekt.
// - memory: En fildataström som används för att läsa/skriva kontaktdata till en fil.
// Returvärde: Inget.
void openContact(long unsigned int& alt, std::vector<Contact>& runTimeMem, std::fstream& memory)
{
     bool inContact = true;
            do
            {
                int altInCont;

                //Utskrift av kontaktinformation
                std::cout << "Namn: " << runTimeMem[alt].firstName << " " << runTimeMem[alt].lastName << "\n\n"
                          << "Adress: " << runTimeMem[alt].address << " " << runTimeMem[alt].postalCode << " " << runTimeMem[alt].city << "\n\n"
                          << "E-postadress: " << runTimeMem[alt].mailAddress << "\n\n"
                          << "Telefonnummer: " << runTimeMem[alt].phoneNumber << "\n\n"
                          << "Födelsedag: " << runTimeMem[alt].birthDay << "\n" << std::endl;

                std::cout << "\n\nMata in:\n--------\n"
                          << "0 - Gå tillbaka\n"
                          << "1 - Radera kontakt\n"
                          << "Alternativ: ";
                
                std::cin >> altInCont;
                std::cin.ignore();

                //Kontrollerar att giltig inmatning har skett
                if (std::cin.fail()) 
                {
                    std::cin.clear();
                    std::cin.ignore();
                }

                switch (altInCont)
                {
                    case 0:
                        inContact = false;
                        break;
                    case 1:
                        emptyTerm();
                        std::cout << "Radering av kontakt..." << std::endl;
                        removeContact(alt,runTimeMem,memory);
                        inContact = false;
                        break;
                    default:
                        emptyTerm();
                        std::cout << "Ogiltig inmatning! Mata in 0 eller 1.\n";
                        break;
                }   


            }while (inContact);
}

// Raderar en kontakt från minnet och uppdaterar både runtime-vektorn och filen med kontaktdata.
// Parametrar:
// - index: Index för kontakten som ska raderas (konstant för att undvika oavsiktliga modifieringar).
// - runTimeMem: En vektor som innehåller kontaktinformation i form av `contact`-objekt.
// - memory: En fildataström som används för att läsa/skriva kontaktdata till en fil.
// Returvärde: Inget.
void removeContact(const long unsigned int& index, std::vector<Contact>& runTimeMem, std::fstream& memory) 
{   //Kontroll att vald index faktiskt finns
    if (index >= runTimeMem.size()) 
    {
        std::cout << "Ogiltigt index! Radering av kontakt misslyckades." << std::endl;
        return;
    }

    //Skapar en säkerhetskopia av minnet
    std::ofstream backUp("backUp.txt");
    if (!backUp.is_open()) 
    {
        std::cout << "Backupfilen kunde ej öppnas! Kontakt har ej raderats." << std::endl;
        return;
    }

    std::string memLine;
    while (std::getline(memory, memLine)) 
    {
        backUp << memLine << "\n";
    }
    backUp.close(); 

    //Radera kontakt på vald index
    runTimeMem.erase(runTimeMem.begin() + index);

    
    memory.close();
    //Öppnar minne på nytt för att överskriva minnet för att ta bort raderad kontakt
    memory.open("memory.txt", std::ios::out | std::ios::trunc);
    if (!memory.is_open()) 
    {
        std::cout << "Minnesfilen kunde ej öppnas! Radering har ej sparats." << std::endl;
        recoverBackUp(runTimeMem, memory);
        return;
    }

    for (const auto& contact : runTimeMem) 
    {
        memory << contact.firstName << ";" << contact.lastName << ";" << contact.address << ";"
               << contact.postalCode << ";" << contact.city << ";" << contact.mailAddress << ";"
               << contact.phoneNumber << ";" << contact.birthDay << "\n";
    }
    memory.close();

    //Öppnar minne så det går att skriva till nya kontakter i slutet
    memory.open("memory.txt", std::ios::in | std::ios::out | std::ios::app);
    
    //Återställer minnet till säkerhetskopia vid fel 
    if (!memory.is_open()) 
    {
        std::cout << "Minnesfilen kunde ej öppnas efter ändring! Återställning krävs." << std::endl;
        recoverBackUp(runTimeMem, memory);
        return;
    }

    //Borttagning av säkerhetskopia
    if (std::remove("backUp.txt") != 0) 
    {
        std::cout << "Backupfilen kunde ej tas bort." << std::endl;
    } 
    else 
    {
        std::cout << "Backupfilen är borttagen." << std::endl;
    }

    std::cout << "Radering av kontakt har genomförts!" << std::endl;
}
