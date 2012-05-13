#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>

int* readArray(const char *filename, int& length);
void writeArray(const char* filename, const int *array, const int length);

#endif
