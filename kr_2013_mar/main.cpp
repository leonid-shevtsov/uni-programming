#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "menu.h"
#include "shop.h"

Shop *theShop;

void mainPrompt() {
  cout << endl << "=== Current shop state" << endl;
  cout << *theShop << endl;
}


void changeName() {
  char buffer[100];
  cout << "New shop name: ";
  cin.getline(buffer, 100);
  theShop->setName(buffer);
}

void changeManager() {
  char buffer[100];
  cout << "New manager name: ";
  cin.getline(buffer, 100);
  theShop->setManager(buffer);
}

void changeNumber() {
  char buffer[100], *ptr;
  cout << "New shop number: ";
  cin.getline(buffer, 100);
  theShop->setNumber(strtol(buffer, &ptr, 10));
}

void changeSalesArea() {
  char buffer[100], *ptr;
  cout << "New sales area: ";
  cin.getline(buffer, 100);
  theShop->setSalesArea(strtof(buffer, &ptr));
}

void changeWarehouseArea() {
  char buffer[100], *ptr;
  cout << "New warehouse area: ";
  cin.getline(buffer, 100);
  theShop->setWarehouseArea(strtof(buffer, &ptr));
}

void appendToFile() {
  fstream shopsFile;

  shopsFile.open("shops.txt", fstream::out | fstream::app);
  theShop->writeToFile(shopsFile);
  shopsFile.close();

  cout << "File updated!" << endl;
}

int shopComparator(const void* shop1, const void* shop2) {
  return strcmp((*(Shop**)shop1)->getName(), (*(Shop**)shop2)->getName());
}

void printFile() {
  Shop** shopList = NULL;
  int shopCount=0, i;

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
      shopList = (Shop**) realloc(shopList, sizeof(Shop*)*(++shopCount));
    }

    *(shopList+shopCount-1) = Shop::readFromFile(shopsFile);
  }

  shopsFile.close();

  if (shopCount > 0) {
    qsort(shopList, shopCount, sizeof(Shop*), &shopComparator);

    for (i=0; i<shopCount; ++i) {
      cout << "=== Shop #"<<i+1<<endl;
      cout << **(shopList+i);
    }
    cout << "====== End of shops file " << endl << endl;

    for (i=0; i<shopCount; ++i) {
      delete *(shopList+i);
    }

    free(shopList);
  } else {
    cout << "Shops.txt is empty!" << endl;
  }
}

void wipeFile() {
  fstream shopsFile;
  shopsFile.open("shops.txt", fstream::out);
  shopsFile.close();
}

const MenuItem mainMenu[] = {
    {"Change shop name", &changeName},
    {"Change manager name", &changeManager},
    {"Change number", &changeNumber},
    {"Change sales area", &changeSalesArea},
    {"Change warehouse area", &changeWarehouseArea},
    {"Append this shop to file (shops.txt)", &appendToFile},
    {"Print list of shops in file ordered by name (shops.txt)", &printFile},
    {"Wipe file (shops.txt)", &wipeFile}
  };

int main(int argc, char** argv) {
  theShop = new Shop("John's shop", "John Doe", 123, 100, 300);

  runMenu(mainPrompt, mainMenu, 8);

  delete theShop;
  return 0;
}