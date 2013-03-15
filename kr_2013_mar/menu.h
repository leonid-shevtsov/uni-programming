#ifndef __MENU_H__
#define __MENU_H__

// A MenuItem consists of a label, and a handler method.
struct MenuItem {
  const char* label;
  void (*handler)();
};

// Menu-driven interface
// * prompt (optional) - this method will be called every time
//    before the menu is rendered
// * commands - a list of commands
// * commandCount - number of commands in the list
void runMenu(void (*prompt)(), const MenuItem* commands, int commandCount);

#endif