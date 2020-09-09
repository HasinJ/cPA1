#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[argc +1]) {
  if (argc>2 || argc==1) {
    printf("Please enter 1 file name.\n");
    return EXIT_SUCCESS;
  }

  FILE *f = fopen(argv[1],"r");
  if (f==0) {
    printf("File doesn't exist.\n");
    return EXIT_SUCCESS;
  }


  for (size_t i = 1; i < argc; i++) {
    printf("%s\n", argv[i]);
  }
}
