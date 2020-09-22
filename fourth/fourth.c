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

  int count=1,row=0,col=(dimsions-1)/2;
  int* current = &matrix[row][col]; //initial row & column
  while (*current!=dimsions*dimsions){
    if(*current!=0){
      row+=1; //going backwards
      col-=1; //going backwards
      row+=1;
      printf("count=%d row=%d col=%d\n", count,row,col);
      current=&matrix[row][col];
      *current=count++;
      row-=1;
      col+=1;
      if(row<0) row=dimsions-1; //go to the last row if upper element is out of reach
      if(col>2) col=0; //go to the first column if righter element is out of reach
      current=&matrix[row][col];
      read(matrix,dimsions);
      continue;
    }
    printf("count=%d row=%d col=%d\n", count,row,col);
    *current=count++;
    row-=1;
    col+=1;
    if(row<0) row=dimsions-1; //go to the last row if upper element is out of reach
    if(col>2) col=0; //go to the first column if righter element is out of reach
    current=&matrix[row][col];
    read(matrix,dimsions);
  }

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
