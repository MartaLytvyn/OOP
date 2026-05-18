#ifndef FABRIC_H
#define FABRIC_H
#include <string>
using namespace std;

class Furniture {
    string Name;
public:
    Furniture(string name) {
        Name = name;
    }
    Furniture() {}
    string getName() { return Name; }
    void setName(string name) { Name = name; }
};

class Chairs : public Furniture {
public:
    Chairs(string name) : Furniture(name) {}
    Chairs() : Furniture() {}
};

class Table : public Furniture {
public:
    Table(string name) : Furniture(name) {}
    Table() : Furniture() {}
};

class FurnitureFactory {
public:
    virtual Chairs* GetChairs() = 0;
    virtual Table* GetTable() = 0;
    virtual ~FurnitureFactory() {}
};

class ModernChairs : public Chairs {
public:
    ModernChairs();
};
class ClassicalChairs : public Chairs {
public:
    ClassicalChairs();
};
class ModernTable : public Table {
public:
    ModernTable();
};
class ClassicalTable : public Table {
public:
    ClassicalTable();
};
class ModernFurniture : public FurnitureFactory {
public:
    Chairs* GetChairs() override;
    Table* GetTable() override;
};
class ClassicalFurnitureFactory : public FurnitureFactory {
public:
    Chairs* GetChairs() override;
    Table* GetTable() override;
};

#endif