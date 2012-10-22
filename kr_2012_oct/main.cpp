#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Trims string of trailing spaces
// (in, out) str: string to be trimmed
// returns: final length of string
int trim_inplace(char* str) {
  int str_len = strlen(str)-1;
  while (str_len>0 && isspace(str[str_len])) str_len--;
  str[str_len+1] = 0;
  return str_len;
}

void tolower_inplace(char* str) {
  char* ptr = str;
  while (*ptr) {
    *ptr = tolower(*ptr);
    ptr++;
  }
}

int main(int argc, char** argv) {
  char sentence[100];
  char word[100];

  printf("Sentence > ");
  fgets(sentence, 100, stdin);
  if (trim_inplace(sentence)==0) {
    printf("Must enter a sentence\n");
    return -1;
  }

  printf("Word > ");
  fgets(word, 100, stdin);
  if (trim_inplace(word)==0) {
    printf("Must enter a word\n");
    return -1;
  }

  // covert both sentence and word to lowercase
  tolower_inplace(sentence);
  tolower_inplace(word);

  int word_index[100];
  int word_count=0, pos=0, final_pos = strlen(sentence);

  while ( pos < final_pos) {
    if (isspace(sentence[pos]))
      sentence[pos++] = 0; // to split into separate words
    else {
      word_index[word_count++] = pos++;
      while (!isspace(sentence[pos])) pos++;
    }
  }

  for (int  i=0; i<word_count; ++i) {
      if (strstr(sentence+word_index[i], word)) {
        printf("Found %s in: %s\n", word, sentence+word_index[i]);
      }
  }

  // Nothing to free, working with stack variables

  return 0;
}