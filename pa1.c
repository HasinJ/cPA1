#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[argc +1]) {
  for (size_t i = 1; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
}
