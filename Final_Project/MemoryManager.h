//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_

#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include "contact.h"

void readFromMem(std::fstream& memory, std::vector<Contact>& runTimeMem);
void recoverBackUp(std::vector<Contact>& runTimeMem, std::fstream& memory);

#endif