#ifndef __SHOP_H__
#define __SHOP_H__

#include <iostream>
using namespace std;

// Task 1

class Shop {
public:
  Shop(const char* name, const char* manager, int number, float salesArea, float warehouseArea);
  ~Shop();

  const char* getName() const;
  const char *getManager() const;
  int getNumber() const;
  float getSalesArea() const;
  float getWarehouseArea() const;

  void setName(const char* name);
  void setManager(const char* manager);
  void setNumber(int number);
  void setSalesArea(float salesArea);
  void setWarehouseArea(float warehouseArea);

  friend ostream& operator<<(ostream& os, const Shop& shop);

  ostream& writeToFile(ostream& os);
  static Shop* readFromFile(istream& is);

  virtual void print();

private:
  char* name;
  char* manager;
  int number;
  float salesArea;
  float warehouseArea;
};

Shop** readShopsFile(int &shopCount);
void sortShopList(Shop** shopList, int shopCount);
void printShopList(Shop** shopList, int shopCount);

// Task 2

class Pharmacy: public Shop {
public:
  Pharmacy(const char* name, const char* manager, int number, float salesArea, float warehouseArea);
  ~Pharmacy();
  virtual void print();
};

class GroceryShop: public Shop {
public:
  GroceryShop(const char* name, const char* manager, int number, float salesArea, float warehouseArea);
  ~GroceryShop();
  virtual void print();
};

void view(Shop* shop);

#endif