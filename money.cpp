#include "money.h"

void Money::addMoney(Money price) {
    grn = grn + price.grn;
    kop = kop + price.kop;

    if (kop >= 100) {
        grn += kop / 100;
        kop = kop % 100;
    }
}

void Money::multyMoney(unsigned short int count) {
    grn = grn * count;
    kop = kop * count;

    if (kop >= 100) {
        grn += kop / 100;
        kop = kop % 100;
    }
}

void Money::aroundMoney() {
    short int division = kop / 10;
    if (kop % 10 > 4) {
        kop = division * 10 + 10;
    } else {
        kop = division * 10;
    }
    if (kop == 100) {
        grn += 1;
        kop = 0;
    }
}
