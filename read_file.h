#ifndef READ_FILE_H
#define READ_FILE_H

#include <vector>
#include <regex>

using namespace std;

void regexToValues(unsigned int& value, string name, vector<string>& words, int index);
void regexToValues(unsigned short int& value, string name, vector<string>& words, int index);
void printCal();

#endif
