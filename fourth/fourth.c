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
  //printf("\n");
}

void RowCol(int** matrix,int* row, int* col,int dimsions){
  int temprow = *row;
  int tempcol = *col;
  temprow-=1;
  tempcol+=1;
  if(temprow<0) temprow=dimsions-1; //go to the last row
  if(temprow>dimsions-1) temprow=0; //go to first row

  if(tempcol<0) tempcol=dimsions-1; //go to last column
  if(tempcol>dimsions-1) tempcol=0; //go to the first column

  if (matrix[temprow][tempcol]!=0) {
    temprow=*row+1;
    tempcol=*col;
    if(temprow>dimsions-1) row=0; //go to first row
  }
  *row=temprow;
  *col=tempcol;
}

void Matrix(int dimsions) {
  int** matrix=calloc(dimsions,sizeof(int*));//rows
  for (int i=0; i<dimsions; i++){
    matrix[i]=calloc(dimsions,sizeof(int*));//columns
  }

  int count=1,row=0,col=(dimsions-1)/2;
  int* current = &matrix[row][col]; //initial row & column

  while (count<dimsions*dimsions){
    current=&matrix[row][col]; //selects
    printf("count=%d row=%d col=%d\n", count,row,col);
    *current=count++;//fills
    read(matrix,dimsions);
    RowCol(matrix,&row,&col,dimsions); //changes
    printf("NEXT count=%d row=%d col=%d\n\n", count,row,col);
  }

  matrix[row][col]=count; //last
  printf("finish:\n");
  read(matrix,dimsions);
  freeEverything(matrix,dimsions);
}

int main(int argc, char *argv[argc+1]) {

  int x=atoi(argv[1]);
  //printf("\ndimensions=%dx%d\n", x,x);
  //checks for even/odd
  if ((x/2)==((x-1)/2)) Matrix(x); //odd
  else printf("error.\n"); //even


}
