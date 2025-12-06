//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#ifndef VALIDATION_H_
#define VALIDATION_H_

#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "contact.h"

bool isOnlyAlpha(const std::string& field);
bool isValidPostalCode(const std::string& field);
bool isValidAdress(const std::string& field);
bool isValidPhoneNumber(const std::string& field);
bool isValidEmail(const std::string& field);
bool isValidBirtday(const std::string& field);

#endif