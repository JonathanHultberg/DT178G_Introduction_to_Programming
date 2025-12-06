//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#ifndef ADDCONTACT_H_
#define ADDCONTACT_H_

#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>
#include "contact.h"
#include "Utility.h"
#include "Validation.h"

void addContact(std::fstream& memory,std::vector<Contact>& runTimeMem);
void readField(std::string& field, const std::string& fieldName, const std::string& prompt);
void formatContact(Contact& tempContact);
void removeBlank(std::string& string);


#endif