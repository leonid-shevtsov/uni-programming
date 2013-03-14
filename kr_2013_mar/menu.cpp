#include <iostream>
#include <iomanip>

#include "menu.h"

using namespace std;

bool readInt(int &i) {
  char buffer[100];
  char *ptr;
  cin.getline(buffer, 100);
  i = strtol(buffer, &ptr, 10);
  return buffer[0] != '\n' && (*ptr == '\n' || *ptr == '\0');
}

void runMenu(void (*prompt)(), const MenuItem* commands, int commandCount) {
  int choice;
  while(1) {
    if (prompt) (*prompt)();
    cout << "=== MENU" << endl;
    for (int i=0;i<commandCount; ++i) {
      cout << setw(2) << i+1 << ": " << commands[i].label << endl;
    }
    cout << " 0: Exit / Return" << endl << "  > ";
    if (!readInt(choice) || (choice>commandCount) || (choice<0)) {
      cout << "Error!" << endl;
      continue;
    } else if (choice==0) {
      break;
    } else {
      cout << endl << endl;
      (*commands[choice-1].handler)();
    }
  };
}
