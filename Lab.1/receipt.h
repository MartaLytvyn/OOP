#ifndef RECEIPT_H
#define RECEIPT_H

#include <iostream>
using namespace std;

struct money {
    int grn;
    short int kop;
};

void init(money &m, int g = 0, short int k = 0);
void add(money &result, const money &a, const money &b);
void multiply(money &result, const money &m, int quantity);
void round(money &m);
void print(const money &m);
void calculateReceipt(money &total);

#endif
