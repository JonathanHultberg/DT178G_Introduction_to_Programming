#ifndef READFORMAT_H_
#define READFORMAT_H_

#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <cctype>

void readFormat(std::ifstream& inFile, std::map<std::string, int>& wordCount);


#endif