#include<stdlib.h>
#include<stdio.h>

void freeEverything(int** matrix, int dimsions){
  for (size_t i = 0; i < dimsions; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void read(int** matrix, int dimsions){
  for (size_t i = 0; i < dimsions; i++) {
    for (size_t j = 0; j < dimsions; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


void Matrix(FILE* f,int dimsions) {
  int** matrix=calloc(dimsions,sizeof(int*));//rows
  for (int i=0; i<dimsions; i++){
    matrix[i]=calloc(dimsions,sizeof(int*));//columns
  }

  int current = matrix[1][(dimsions/2)+1],count=0;
  while (current!=5){
    count++;
    printf("%d\n", count);
    matrix[2][2]=5;
    current=matrix[2][2];
  }

  read(matrix,dimsions);
  freeEverything(matrix,dimsions);
}

int main(int argc, char *argv[argc+1]) {
  if (argc>2 || argc==1) {
    printf("Please enter 1 file name.\n");
    return EXIT_SUCCESS;
  }

  FILE *f;
  f = fopen(argv[1],"r");
  if (f==0) {
    printf("error.\n");
    return EXIT_SUCCESS;
  }

  int x;
  fscanf(f,"%d",&x);
  printf("\ndimensions=%dx%d\n", x,x);
  //checks for even/odd
  if ((x/2)==((x-1)/2)) Matrix(f,x); //odd
  else printf("error.\n");


}
