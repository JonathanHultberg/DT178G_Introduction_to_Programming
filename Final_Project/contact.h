//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>

struct Contact
{
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string postalCode;
    std::string city;
    std::string mailAddress;
    std::string phoneNumber;
    std::string birthDay;
};

#endif