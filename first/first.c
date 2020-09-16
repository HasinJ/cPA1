#include<stdio.h>
#include<stdlib.h>

void prime(int x){
  for (size_t i = 2; i < x/2; i++) {
    if(x%i==0) {
      printf("no\n");
      return;}
  }
  printf("yes\n");
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

  char content[10];
  while (fscanf(f,"%[^\n]\n",content) != EOF ) {
    prime(atoi(content));
  }
}
