#include<stdio.h>
#include<stdlib.h>

const char *prime(int x){
  do {
    x-=2;
    if (x==1) return "yes";
    else if (x==0) return "no";

  } while(x!=0 || x!=1);
  return "Error.";
}

int main(int argc, char* argv[argc +1]) {
  if (argc>2 || argc==1) {
    printf("Please enter 1 file name.\n");
    return EXIT_SUCCESS;
  }

  FILE *f;
  f = fopen(argv[1],"r");
  if (f==0) {
    printf("File error.\n");
    return EXIT_SUCCESS;
  }

  int num=0;
  char content[10];
  while (fscanf(f,"%[^\n]\n",content) != EOF ) {
    printf("%s\n", prime(atoi(content)));
    num++;
  }
}
