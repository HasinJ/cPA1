#include<stdio.h>
#include<stdlib.h>

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


  printf("other way:\n");
  int num=0;
  char content[10];
  while (fscanf(f,"%[^\n]\n",content) != EOF ) {
    num++;
  }


  f = fopen(argv[1],"r");
  int *numbers = (int*) malloc(num * sizeof(int));
  for (size_t i = 0; i < num; ++i) {
    int number;
    fscanf(f,"%d\n",&number);
    numbers[i]=number;
    printf("%d\n", numbers[i]);
  }
  fclose(f);
  free(numbers);


  for (size_t i = 1; i < argc; i++) {
    printf("%s\n", argv[i]);
  }


}
