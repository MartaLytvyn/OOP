#include <iostream>
#include <fstream>
#include "receipt.h"

using namespace std;

int main() {

    ifstream file("input.txt");

    if (!file) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    money total;

    int g, k, quantity;

    while (file >> g >> k >> quantity) {
        money cina(g, k);
        money sum = cina.multiply(quantity);
        total = total.add(sum);
    }

    cout << "Загальна сума: ";
    total.print();

    money rounded = total;
    rounded.round();

    cout << "Сума до оплати (після заокруглення): ";
    rounded.print();

    return 0;
}
