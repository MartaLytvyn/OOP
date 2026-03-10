#include <iostream>
#include <fstream>
#include "receipt.h"

void init(money &m, int g, short int k) {
    m.grn = g + k / 100;
    m.kop = k % 100;
}

void add(money &result, const money &a, const money &b) {
    result.grn = a.grn + b.grn;
    result.kop = a.kop + b.kop;

    if (result.kop >= 100) {
        result.grn += result.kop / 100;
        result.kop %= 100;
    }
}

void multiply(money &result, const money &m, int quantity) {
    result.grn = m.grn * quantity;
    result.kop = m.kop * quantity;

    if (result.kop >= 100) {
        result.grn += result.kop / 100;
        result.kop %= 100;
    }
}

void round(money &m) {
    int remainder = m.kop % 10;

    if (remainder >= 8)
        m.kop += (10 - remainder);
    else
        m.kop -= remainder;

    if (m.kop >= 100) {
        m.grn += 1;
        m.kop -= 100;
    }
}

void print(const money &m) {
    cout << m.grn << " грн "
    << m.kop << " коп" << endl;
}
 
void calculateReceipt(money &total) {
    
    ifstream file("input.txt");
    if (!file) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    };
    init(total, 0, 0);   
    int g, k, quantity;

    while (file >> g >> k >> quantity) {

        if (g < 0 || k < 0 || quantity < 0) {
        cout << "Помилка: від'ємні значення у файлі!" << endl;
        return;
       }

        money cina;
        init(cina, g, k);

        money sum;
        multiply(sum, cina, quantity);

        money temp;
        add(temp, total, sum);

        total = temp;
    }
    file.close();
    cout << "Загальна сума: ";
    print(total);
    money rounded = total;
    round(rounded);
    cout << "Сума до оплати (після заокруглення): ";
    print(rounded);
    return;
}
