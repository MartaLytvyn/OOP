#include "receipt.h"
money::money(int g, short k) {
    grn = g + k / 100;
    kop = k % 100;
}
money money::add(const money& other) const {
    int totalK = (grn * 100 + kop) +
                 (other.grn * 100 + other.kop);

    return money(totalK / 100, totalK % 100);
}
money money::multiply(int quantity) const {
    int totalK = (grn * 100 + kop) * quantity;
    return money(totalK / 100, totalK % 100);
}
void money::round() {
    int totalK = grn * 100 + kop;
    int remainder = totalK % 10;

    if (remainder >= 5)
        totalK += (10 - remainder);
    else
        totalK -= remainder;

    grn = totalK / 100;
    kop = totalK % 100;
}
void money::print() const {
    cout << grn << " грн "
         << kop << " коп" << endl;
}