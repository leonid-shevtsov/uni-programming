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


void printFile() {
  Shop** shopList = NULL;
  int shopCount=0, i;

  shopList = readShopsFile(shopCount);

  if (shopCount > 0) {
    sortShopList(shopList, shopCount);
    printShopList(shopList, shopCount);

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