#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[argc +1]) {
  if (argc>2 || argc==1) {
    printf("Please enter 1 file name.\n");
    return EXIT_SUCCESS;
  }

  FILE *f;
  f = fopen(argv[1],"r");
  if (f==0 || f==NULL) {
    printf("File error.\n");
    return EXIT_SUCCESS;
  }

  int i=0;
  char line = fgetc(f);
  while (line!=EOF) {
    printf("%c", line);
    line = fgetc(f);
    i++;
  }
  printf("\n%d\n", n);

  printf("other way:\n");
  int x=0;
  int number;
  while (fscanf(f,"%[^\n]\n",number) != EOF ) {
    printf("%d\n", number);
    x++;
  }

/*
  int *numbers = (int*) malloc(n * sizeof(int));
  for (size_t i = 0; i < n; ++i) {
    printf("%c", line);
    //fscanf(f, "%d", numbers+i);
    line = fgetc(f);
  }
  fclose(f);
  free(numbers);
*/
  for (size_t i = 1; i < argc; i++) {
    printf("%s\n", argv[i]);
  }


}
