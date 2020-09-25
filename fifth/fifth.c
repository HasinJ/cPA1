#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

void freeEverything(int** matrix,int dimsions){
  for (size_t i = 0; i < dimsions; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void read(int **matrix, int dimsions){
  for (size_t i = 0; i < dimsions; i++) {
    for (size_t j = 0; j < dimsions; j++) {
      printf("%d \t",matrix[i][j]);
    }
    printf("\n");
  }
}

void getAnswer(int** matrix, int dimsions, int* answer){
  if (dimsions==1){
    *answer = matrix[0][0];
    return;
  } else{
    if (dimsions==2){
      int a=matrix[0][0],b=matrix[0][1],c=matrix[1][0],d=matrix[1][1];
      *answer = (a*d)-(b*c);
      return;
    }else{
      if (dimsions>2) {
        //delete the rows and columns we dont want for now


        return;
      }
    }
  }


}

void fill(FILE* f, int** matrix,int dimsions){
  int x;
  for (size_t i = 0; i < dimsions; i++) {
    for (size_t j = 0; j < dimsions; j++) {
      fscanf(f,"%d\t",&x);
      matrix[i][j]=x;
    }
  }
  int answer;
  getAnswer(matrix,dimsions,&answer);
  printf("answer=%d\n",answer);
}

void Matrix(FILE* f,int dimsions){
  int **matrix=calloc(dimsions,sizeof(int*));
  for (size_t i = 0; i < dimsions; i++) {
    matrix[i]=calloc(dimsions,sizeof(int*));
  }
  fill(f,matrix,dimsions);
  read(matrix,dimsions);
  freeEverything(matrix,dimsions);
}

int main(int argc, char const *argv[argc+1]) {
  if (argc>2 || argc==1) {
    printf("Please enter 1 file name.\n");
    return EXIT_SUCCESS;
  }

  FILE *f;
  f = fopen(argv[1],"r");
  if (f==0) {
    printf("error\n");
    return EXIT_SUCCESS;
  }

  int dimsions;
  fscanf(f,"%d\n",&dimsions);
  if(dimsions>20 || dimsions<=0){
    printf("error\n");
    return EXIT_SUCCESS;
  };

  Matrix(f,dimsions);

  return EXIT_SUCCESS;
}
