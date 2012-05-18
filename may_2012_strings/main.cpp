#include <cstdlib>
#include <cstdio>
#include <cstring>

void strcpy_multi(char* dst, const char* src, int count) {
  char* target = dst;
  int step = strlen(src);
  for (int i=0; i<count; ++i) {
    strcpy(target, src);
    target += step;
  }
}

int main() {
  char source[80]; // 80 chars should be enough for everybody
  unsigned int count;

  printf("String without spaces: ");
  scanf("%s", source); 
  printf("Reps count: ");
  scanf("%u", &count);

  char* dest = (char*)malloc(strlen(source)*count+1);

  strcpy_multi(dest, source, count);

  printf("Result: %s\n", dest);

  delete dest;

  return 0;
};
