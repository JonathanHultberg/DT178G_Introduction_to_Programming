//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#include "AddContact.h"

// Lägger till en ny kontakt i minnet och uppdaterar filen med kontaktdata.
// Parametrar:
// - memory: En fildataström för att läsa/skriva kontaktdata till en fil.
// - runTimeMem: En vektor som innehåller kontaktinformation i form av `contact`-objekt.
// Returvärde: Inget.
void addContact(std::fstream& memory,std::vector<Contact>& runTimeMem)
{
    emptyTerm();
    memory.clear();

    //Hjälp från: cplusplus.com
    memory.seekp(0,std::ios::end);
    // Slut hjälp

    Contact tempContact;
    std::string checkBlank;

    std::cout << "Skapa kontakt | Fyll i nedanstående fält, avsluta med Enter |\n"
              << "Om fält lämnas tomt, fylls det med (---)\n"
              << "---------------------------------------------------------------" << std::endl;
    
    //Inläsning för fält i kontakt
    do
    {
        readField(tempContact.firstName, "förnamn", "Skriv in förnamn: ");
    } while (!isOnlyAlpha(tempContact.firstName));

    do
    {
        readField(tempContact.lastName, "efternamn", "Skriv in efternamn: ");
    } while (!isOnlyAlpha(tempContact.lastName));

    do
    {
        readField(tempContact.address, "adress", "Skriv in adress, både väg/gata samt nummer: ");
    } while (!isValidAdress(tempContact.address));

    do
    {
        readField(tempContact.postalCode, "postkod", "Skriv in postkod, utan mellanslag: ");
    } while (!isValidPostalCode(tempContact.postalCode));

    do
    {
        readField(tempContact.city, "stad/ort", "Skriv in stad/ort: ");
    } while (!isOnlyAlpha(tempContact.city));

    do
    {
        readField(tempContact.mailAddress, "e-postadress", "Skriv in e-postadress: ");
    } while (!isValidEmail(tempContact.mailAddress));

    do
    {
        readField(tempContact.phoneNumber, "telefonnummer", "Skriv in telefonnummer, utan bindestreck (-) och utan mellanslag: ");
    } while (!isValidPhoneNumber(tempContact.phoneNumber));

    do
    {
        readField(tempContact.birthDay, "födelsedag", "Skriv in födelsedag, på formen ÅÅÅÅ-MM-DD: ");
    } while (!isValidBirtday(tempContact.birthDay));
    
    std::cout << "Kontakt sparas" << std::endl;

    formatContact(tempContact);

    //Kontakt sparas till minnet samt till runTimeMem
    memory << tempContact.firstName << ";" << tempContact.lastName << ";" << tempContact.address << ";"
           << tempContact.postalCode << ";" << tempContact.city << ";" << tempContact.mailAddress << ";"
           << tempContact.phoneNumber << ";" << tempContact.birthDay << "\n";

    runTimeMem.push_back(tempContact);

    //Hjälp från: geeksforgeeks.org
    std::sort(runTimeMem.begin(),runTimeMem.end(), [](const Contact& a, const Contact& b){
        return a.lastName < b.lastName;
    });
    //Slut hjälp!
}

// Lägger till en ny kontakt i minnet och uppdaterar filen med kontaktdata.
// Parametrar:
// - memory: En fildataström för att läsa/skriva kontaktdata till en fil.
// - runTimeMem: En vektor som innehåller kontaktinformation i form av `contact`-objekt.
// Returvärde: Inget.
void readField(std::string& field, const std::string& fieldName, const std::string& prompt)
{
    bool running = true;
    char emptyCheck;

    do {
        std::cout << prompt;
        std::getline(std::cin, field);
        
        //Hjälp från: cplusplus.com
        if (std::all_of(field.begin(), field.end(), isspace) || field.empty()) 
        //Slut hjälp
        {
            std::cout << "Vill du lämna fältet " << fieldName << " tomt?\nTomt fält ersätts med (---)\n"
                      << "[ J | N ]: ";
            std::cin >> emptyCheck;
            std::cin.ignore();  

            if (emptyCheck == 'j' || emptyCheck == 'J') 
            {
                field = "---";
                running = false;
            } 

        } else {
            running = false;
        }
    } while (running);

    removeBlank(field);
}

// Formaterar en kontakts fält enligt regler för stora och små bokstäver.
// Parametrar:
// - tempContact: Referens till ett kontaktobjekt vars fält ska formateras.
// Returvärde: Inget.
void formatContact(Contact& tempContact)
{
    std::transform(tempContact.firstName.begin(),tempContact.firstName.end(),tempContact.firstName.begin(),tolower);
    tempContact.firstName[0] = std::toupper(tempContact.firstName[0]);

    std::transform(tempContact.lastName.begin(),tempContact.lastName.end(),tempContact.lastName.begin(),tolower);
    tempContact.lastName[0] = std::toupper(tempContact.lastName[0]);

    std::transform(tempContact.address.begin(),tempContact.address.end()-1,tempContact.address.begin(),tolower);
    tempContact.address[0] = std::toupper(tempContact.address[0]);
    tempContact.address[tempContact.address.length()-1] = std::toupper(tempContact.address[tempContact.address.length()-1]);

    std::transform(tempContact.city.begin(),tempContact.city.end(),tempContact.city.begin(),tolower);
    tempContact.city[0] = std::toupper(tempContact.city[0]);

    std::transform(tempContact.mailAddress.begin(),tempContact.mailAddress.end(),tempContact.mailAddress.begin(),tolower);
}

// Tar bort inledande och avslutande blanksteg från en sträng.
// Parametrar:
// - string: Referens till en sträng som ska bearbetas.
// Returvärde: Inget.
void removeBlank(std::string& string)
{
    while(isblank(string[0]))
        {
            string.erase(0,1);
        }
    
    while(isblank(string[string.length()-1]))
        {
            string.erase(string.length()-1,1);
        }
}