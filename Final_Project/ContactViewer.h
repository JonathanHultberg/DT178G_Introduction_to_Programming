//Jonathan Hultberg
//2025-01-13
//DT178G Introduktion till programmering
//Projekt alternativ 2: Contacts

#ifndef CONTACTVIEWER_H_
#define CONTACTVIEWER_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include "contact.h"
#include "Utility.h"
#include "MemoryManager.h"

void viewContacts(std::vector<Contact>& contactList,std::fstream& memory);
void search(std::vector<Contact>& runTimeMem, std::fstream& memory);
void openContact(long unsigned int& alt, std::vector<Contact>& runTimeMem, std::fstream& memory);
void removeContact(const long unsigned int& index, std::vector<Contact>& runTimeMem,std::fstream& memory);

#endif