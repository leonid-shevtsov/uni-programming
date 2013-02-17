#ifndef __SHOP_H__
#define __SHOP_H__

#include <iostream>
using namespace std;

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
private:
  char* name;
  char* manager;
  int number;
  float salesArea;
  float warehouseArea;
};


#endif