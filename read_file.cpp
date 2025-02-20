#include <fstream>
#include <Windows.h>
#include <iostream>
#include "read_file.h"
#include "money.h"

void regexToValues(unsigned int& value, string name, vector<string>& words, int index) {
    if (regex_match(words[index], regex("^" + name + "[[:punct:]]*$"))) {
        try {
            value = stoul(words[index - 1]);
        } catch (const invalid_argument&) {
            cerr << "Помилка: некоректне значення " + name << endl;
        }
    }
}

void regexToValues(unsigned short int& value, string name, vector<string>& words, int index) {
    if (regex_match(words[index], regex("^" + name + "[[:punct:]]*$"))) {
        try {
            value = stoul(words[index - 1]);
        } catch (const invalid_argument&) {
            cerr << "Помилка: некоректне значення " + name << endl;
        }
    }
}

void printCal() {
    SetConsoleOutputCP(CP_UTF8);

    Money total = {0, 0};

    ifstream file("C:/Users/Danko/Desktop/Projects/OOP/Lab_1/test.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            unsigned int grn = 0;
            unsigned short int kop = 0, count = 1;
            int index = 0;
            size_t start = 0;
            size_t end = line.find(' ');

            vector <string> words;
            words.push_back(line.substr(start, end - start));

            while (end != string::npos) {
                index++;
                start = end + 1;
                end = line.find(' ', start);

                words.push_back(line.substr(start, end - start));

                regexToValues(grn, "грн", words, index);
                regexToValues(kop, "коп", words, index);
                regexToValues(count, "шт", words, index);
            }

            Money product = {grn, kop};
            product.multyMoney(count);
            total.addMoney(product);
        }
        file.close();
    }
    cout << "Загальна сума: " << total.grn << " грн " << total.kop << " коп" << endl;
    total.aroundMoney();
    cout << "Сума після заокруглення: " << total.grn << " грн " << total.kop << " коп" << endl;

}
