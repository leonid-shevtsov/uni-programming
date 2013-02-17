#include <cstring>
#include "shop.h"

Shop::Shop(const char* _name, const char* _manager, int _number, float _salesArea, float _warehouseArea):
  number(_number),
  salesArea(_salesArea),
  warehouseArea(_warehouseArea)
{
  name = strdup(_name);
  manager = strdup(_manager);
}

Shop::~Shop() {
  free(name);
  free(manager);
}

const char* Shop::getName() const {
  return name;
}

const char *Shop::getManager() const {
  return manager;
}

int Shop::getNumber() const {
  return number;
}

float Shop::getSalesArea() const {
  return salesArea;
}

float Shop::getWarehouseArea() const {
  return warehouseArea;
}


void Shop::setName(const char* _name) {
  delete name;
  name = strdup(_name);
}

void Shop::setManager(const char* _manager) {
  delete manager;
  manager = strdup(_manager);
}

void Shop::setNumber(int _number) {
  number = _number;
}

void Shop::setSalesArea(float _salesArea) {
  salesArea = _salesArea;
}

void Shop::setWarehouseArea(float _warehouseArea) {
  warehouseArea = _warehouseArea;
}

ostream& operator<<(ostream& os, const Shop& shop) {
  os << "Shop name: " << shop.getName() << endl;
  os << "Number: " << shop.getNumber() << endl;
  os << "Manager name: " << shop.getManager() << endl;
  os << "Sales area: " << shop.getSalesArea() << endl;
  os << "Warehouse area: " << shop.getWarehouseArea() << endl;
  return os;
}
