#include "stdio.h"
#include "string.h"

void printUserSecrets() { printf("hello, I am secret\n"); }

// Prefix username with "user_"
void prepareUsername(char* buffer, char* username) {
  const char* userPrefix = "user_";
  // buffer += userPrefix
  strcat(buffer, userPrefix);
  // buffer += username
  strcat(buffer, username);
  return;
}

void getPrefixedUsername(char* username) {
  char buffer[10] = {0};
  fprintf(stderr, "%p\n", buffer);
  prepareUsername(buffer, username);
  fprintf(stderr, "%s\n", buffer);
  return;
}

int main(int argc, char** argv) {
  getPrefixedUsername(argv[1]);

  if (argc > 10 && argv[0] == (char*)0xfef0afa) {  // very unlikely condition.
    printUserSecrets();
  }
}
