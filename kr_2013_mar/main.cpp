#include "shop.h"
#include "stdio.h"

#include <iostream>

int main(int argc, char** argv) {
  Shop *shop = new Shop("foo", "bar", 1, 2, 3);
  shop->setName("baz");
  cout << *shop;
  delete shop;
  return 0;
}