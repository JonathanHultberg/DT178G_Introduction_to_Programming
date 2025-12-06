//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#include "Validation.h"

// Kontrollera om ett fält endast innehåller bokstäver eller är tomt (ersatt med "---").
// Parametrar:
// - field: Den sträng som ska kontrolleras.
// Returvärde:
// - true om fältet endast innehåller bokstäver eller är tomt, annars false.
bool isOnlyAlpha(const std::string& field)
{
    if(field == "---")
    {
        return true;
    }

    if(std::all_of(field.begin(),field.end(),isalpha))
    {
        return true;
    }

    else 
    {   
        std::cout << "Fel format!" << std::endl;
        return false;
    }

}

// Kontrollera om ett fält är ett giltigt postnummer (5 siffror).
// Parametrar:
// - field: Den sträng som ska kontrolleras.
// Returvärde:
// - true om fältet är ett giltigt postnummer, annars false.
bool isValidPostalCode(const std::string& field)
{
    if(field == "---")
    {
        return true;
    }

    if(std::all_of(field.begin(),field.end(),isdigit) && (field.length() == 5))
    {
        return true;
    }

    else 
    {   
        std::cout << "Fel format!" << std::endl;
        return false;
    }
}

// Kontrollera om ett fält är ett giltigt adressformat (måste innehålla både bokstäver och siffror).
// Parametrar:
// - field: Den sträng som ska kontrolleras.
// Returvärde:
// - true om fältet är ett giltigt adressformat, annars false.
bool isValidAdress(const std::string& field)
{
    if(field == "---")
    {
        return true;
    }

    bool hasLetter = false;
    bool hasDigit = false;

    for (char c : field)
    {
        if (std::isalpha(c)) 
        {
            hasLetter = true;
        }
        
        if (std::isdigit(c)) 
        {  
            hasDigit = true;
        }  
        
    }

    if(!(hasLetter && hasDigit))
    {
        std::cout << "Fel format!" << std::endl;
    }

    return hasLetter && hasDigit;
}

// Kontrollera om ett fält är ett giltigt telefonnummer (10 siffror).
// Parametrar:
// - field: Den sträng som ska kontrolleras.
// Returvärde:
// - true om fältet är ett giltigt telefonnummer, annars false.
bool isValidPhoneNumber(const std::string& field)
{
    if(field == "---")
    {
        return true;
    }

    if(std::all_of(field.begin(),field.end(),isdigit) && (field.length() == 10))
    {
        return true;
    }

    else 
    {   
        std::cout << "Fel format!" << std::endl;
        return false;
    }
}

// Kontrollera om ett fält är en giltig e-postadress (måste innehålla '@').
// Parametrar:
// - field: Den sträng som ska kontrolleras.
// Returvärde:
// - true om fältet är en giltig e-postadress, annars false.
bool isValidEmail(const std::string& field)
{
    if(field == "---")
    {
        return true;
    }

    if(field.find('@') != std::string::npos)
    {
        return true;
    }

    else 
    {   
        std::cout << "Fel format!" << std::endl;
        return false;
    }
}

// Kontrollera om ett fält är ett giltigt födelsedagsformat (ÅÅÅÅ-MM-DD).
// Parametrar:
// - field: Den sträng som ska kontrolleras.
// Returvärde:
// - true om fältet är ett giltigt födelsedagsformat, annars false.
bool isValidBirtday(const std::string& field)
{
    if(field == "---")
    {
        return true;
    }
    
    int hyphenCount = std::count(field.begin(), field.end(), '-');

    if (hyphenCount == 2)
    {
        std::string strYear, strMonth, strDay;

        //Hjälp från cplusplus.com
        strYear = field.substr(0,4);
        strMonth = field.substr(5,2);
        strDay = field.substr(8,2);
        //Slut hjälp

        if(!std::all_of(strYear.begin(),strYear.end(),isdigit))
        {
            std::cout << "Fel format!" << std::endl;
            return false;
        }

        if(!std::all_of(strMonth.begin(),strMonth.end(),isdigit))
        {
            std::cout << "Fel format!" << std::endl;
            return false;
        }

        if(!std::all_of(strDay.begin(),strDay.end(),isdigit))
        {
            std::cout << "Fel format!" << std::endl;
            return false;
        }

        return true;
    }

    else 
    {
        std::cout << "Fel format!" << std::endl;
        return false;
    }
}