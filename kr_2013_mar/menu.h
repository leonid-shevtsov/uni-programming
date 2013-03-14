#ifndef __MENU_H__
#define __MENU_H__

struct MenuItem {
  const char* label;
  void (*handler)();
};

void runMenu(void (*prompt)(), const MenuItem* commands, int commandCount);

#endif