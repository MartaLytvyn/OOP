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
