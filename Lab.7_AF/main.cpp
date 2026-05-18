#include <iostream>
#include "Fabric.h"
using namespace std;

int main()
{
    FurnitureFactory* factory = new ModernFurniture();
    Chairs* chairs = factory->GetChairs();
    Table* table = factory->GetTable();

    cout << "I've got " << chairs->getName()
         << " and " << table->getName() << endl;

    delete chairs;
    delete table;
    delete factory;
    return 0;
}