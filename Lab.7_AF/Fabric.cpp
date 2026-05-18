#include "Fabric.h"

ModernChairs::ModernChairs() : Chairs("Modern Chairs") {}
ClassicalChairs::ClassicalChairs() : Chairs("Classical Chairs") {}

ModernTable::ModernTable() : Table("Modern Table") {}
ClassicalTable::ClassicalTable() : Table("Classical Table") {}

Chairs* ModernFurniture::GetChairs() { return new ModernChairs(); }
Table* ModernFurniture::GetTable() { return new ModernTable(); }

Chairs* ClassicalFurnitureFactory::GetChairs() { return new ClassicalChairs(); }
Table* ClassicalFurnitureFactory::GetTable() { return new ClassicalTable(); }