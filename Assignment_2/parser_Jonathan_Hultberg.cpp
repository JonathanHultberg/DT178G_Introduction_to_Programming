//Jonathan Hultberg
//Datum: 241125
//Kurs: DT178G
//Laboration 2

#include <string>
#include <iostream>
#include <fstream>

std::string getGenderFromSSN (std::string ssn);

int main() 
{  
    std::string firstName, lastName, ssn, address, genderLabel;
    
    std::ifstream inFile;
    inFile.open("names.txt");

    std::ofstream outFile;
    outFile.open("out.txt"); 
    
    if(!inFile.is_open())
    {
        std::cout << "In filen gick ej att öppna" << std::endl;
        return -1;
    }

    if(!outFile.is_open())
    {
        std::cout << "Ut filen gick ej att öppna" << std::endl;
        return -2;
    }
    
    while(std::getline(inFile, firstName, ' ') && std::getline(inFile, lastName) &&
          std::getline(inFile, ssn) && std::getline(inFile, address))
    {
        //separat funktion
        genderLabel = getGenderFromSSN (ssn);

        outFile << lastName << ", " << firstName << " " << genderLabel << "\n" << address << "\n\n"; 
    }

    inFile.close();
    outFile.close();

    return 0;
}

//funktion som avgör könsmarkör beroende på nästsista siffran i personnummret
std::string getGenderFromSSN (std::string ssn)
{
    char secondLastDigit;
    int genderDigit;

    secondLastDigit = ssn[ssn.length()-2];
    genderDigit = secondLastDigit-'0';

    if(genderDigit%2==0)
    {
        return "[K]";
    }
    else
    {
        return "[M]";
    }
}


