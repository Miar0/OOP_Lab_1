#ifndef MONEY_H
#define MONEY_H

struct Money {
    unsigned int grn;
    unsigned short int kop;

    void addMoney(Money price);
    void multyMoney(unsigned short int count);
    void aroundMoney();
};

#endif
