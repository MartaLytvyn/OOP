#include <iostream>
#include <fstream>
#include "receipt.h"

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
    }

    total.grn = 0;
    total.kop = 0;

    int g, quantity;
    short int k;

    while (file >> g >> k >> quantity) {

        if (g < 0 || k < 0 || quantity < 0) {
            cout << "Помилка: від'ємні значення у файлі!" << endl;
            return;
        }

        money cina = {g, k};

        money sum;
        multiply(sum, cina, quantity);

        add(total, total, sum);
    }

    file.close();

    cout << "Загальна сума: ";
    print(total);

    money rounded = total;
    round(rounded);

    cout << "Сума до оплати (після заокруглення): ";
    print(rounded);
}
