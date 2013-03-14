#include <cstring>
#include <iomanip>
#include <fstream>
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
  os << setw(20) << "Shop name: " << shop.getName() << endl;
  os << setw(20) << "Number: " << shop.getNumber() << endl;
  os << setw(20) << "Manager name: " << shop.getManager() << endl;
  os << setw(20) << "Sales area: " << shop.getSalesArea() << endl;
  os << setw(20) << "Warehouse area: " << shop.getWarehouseArea() << endl;
  return os;
}

ostream& Shop::writeToFile(ostream& os) {
  os << getName() << endl;
  os << getNumber() << endl;
  os << getManager() << endl;
  os << getSalesArea() << endl;
  os << getWarehouseArea() << endl;
  return os;
};

Shop* Shop::readFromFile(istream& is) {
  char name[100];
  char manager[100];
  char buffer[100], *ptr;
  int number;
  float salesArea;
  float warehouseArea;

  is.getline(name, 100);
  is.getline(buffer, 100);
  number = strtol(buffer, &ptr, 10);
  is.getline(manager, 100);
  is.getline(buffer, 100);
  salesArea = strtof(buffer, &ptr);
  is.getline(buffer, 100);
  warehouseArea = strtof(buffer, &ptr);

  return new Shop(name, manager, number, salesArea, warehouseArea);
}

Shop** readShopsFile(int &shopCount) {
  Shop** shopList = NULL;
  shopCount=0;

  fstream shopsFile;
  shopsFile.open("shops.txt", fstream::in);

  while (1) {
    // fix error with last shop not moving to EOF, by reading one char ahead
    char lastchar;
    shopsFile.read(&lastchar, 1);
    if (shopsFile.eof())  {
      break;
    } else {
      shopsFile.putback(lastchar);
    }

    if (!shopList) {
      ++shopCount;
      shopList = (Shop**) malloc(sizeof(Shop*));
    } else {
      // Grow array by another element. Not most efficient with memory, but avoids reading file twice
      // (which also requires allocating memory).
      shopList = (Shop**) realloc(shopList, sizeof(Shop*)*(++shopCount));
    }

    *(shopList+shopCount-1) = Shop::readFromFile(shopsFile);
  }

  shopsFile.close();

  return shopList;
}

int shopComparator(const void* shop1, const void* shop2) {
  return strcmp((*(Shop**)shop1)->getName(), (*(Shop**)shop2)->getName());
}

void sortShopList(Shop** shopList, int shopCount) {
  qsort(shopList, shopCount, sizeof(Shop*), &shopComparator);
}

void printShopList(Shop** shopList, int shopCount) {
  for (int i=0; i<shopCount; ++i) {
    cout << "=== Shop #"<<i+1<<endl;
    cout << **(shopList+i);
  }
  cout << "====== End of shops file " << endl << endl;
}