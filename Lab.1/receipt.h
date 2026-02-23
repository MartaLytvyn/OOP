#ifndef RECEIPT_H
#define RECEIPT_H
#include <iostream>
using namespace std;
struct money {
int grn;
short int kop;
money (int g = 0, short int k = 0);
money add (const money& other) const;
money multiply (int quantity) const;
void round();
void print () const;
};
#endif 