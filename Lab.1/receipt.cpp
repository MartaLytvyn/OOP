#include <iostream>
#include <fstream>
#include "receipt.h"

int toKop (const money &m){
    return m.grn * 100 + m.kop;
}

void fromKop (money &m, int totalKop)
{
m.grn = totalKop / 100;
m.kop = totalKop % 100;
}

void init(money &m, int g, short int k) {
    m.grn = g + k / 100;
    m.kop = k % 100;
}

void add(money &result, const money &a, const money &b) {
    int totalK = toKop(a) + toKop(b);
    fromKop (result, totalK); 
}

void multiply(money &result, const money &m, int quantity) {
    int totalK = toKop(m) * quantity;
    fromKop(result, totalK);
}

void round(money &m) {
    int totalK = toKop(m);
    int remainder = totalK % 10;

    if (remainder >= 8)
        totalK += (10 - remainder);
    else
        totalK -= remainder;

        fromKop(m, totalK);
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
