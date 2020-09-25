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

void getAnswer(int** matrix, int**temp, int dimsions, int* answer, int* deletedrow, int* deletedcol){
  if (dimsions==1){
    *answer = matrix[0][0];
    return;
  } else{
    if (dimsions==2){
      int a=matrix[0][0],b=matrix[0][1],c=matrix[1][0],d=matrix[1][1];
      *answer += ((a*d)-(b*c));
      return;
    }else{
      if (dimsions>2) {
        //delete the rows and columns we dont want for now
        temp=calloc(dimsions-1,sizeof(int*));
        for (size_t i = 0; i < dimsions-1; i++) {
          temp[i]=calloc(dimsions-1,sizeof(int*));
        }

        int tempi=0,tempj=0;
        for (size_t i = 0; i < dimsions; i++) {
          if (i==*deletedrow) continue;
          tempj=0;
          for (size_t j = 0; j < dimsions; j++) {
            if (j==*deletedcol) continue;
            //printf("delete stuff row first: %d %d\n", *deletedrow,*deletedcol);
            //printf("i=%ld j=%ld\n",i,j);
            temp[tempi][tempj++]=matrix[i][j];
          }
          tempi++;
        }

        int a=temp[0][0],b=temp[0][1],c=temp[1][0],d=temp[1][1];

        if ((*deletedcol+1/2)==((*deletedcol)/2) || *deletedcol+1==3) {
          *answer += (matrix[*deletedrow][*deletedcol])*((a*d)-(b*c)); //odd
          //printf("\nanswer for now=%d %d*%d\n", *answer,(matrix[*deletedrow][*deletedcol]),((a*d)-(b*c)));
        }else {
          *answer -= (matrix[*deletedrow][*deletedcol])*((a*d)-(b*c)); //even
          //printf("\nanswer for now=%d %d*%d\n", *answer,(matrix[*deletedrow][*deletedcol]),((a*d)-(b*c)));
        }

        //printf("\ntemp:\n");
        //read(temp,dimsions-1);
        //printf("\n");
        freeEverything(temp,dimsions-1);
        if(*deletedcol==dimsions-1) {
          return;
        }
        /*
        temp=calloc(dimsions,sizeof(int*));
        for (size_t i = 0; i < dimsions; i++) {
          temp[i]=calloc(dimsions,sizeof(int*));
          for (size_t j = 0; j < dimsions; j++) {
            temp[i][j]=matrix[i][j];
          }
        }
        */
        *deletedcol= *deletedcol+1;
        getAnswer(matrix,temp,dimsions,answer,deletedrow,deletedcol);
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
  int answer=0,deletedcol=0,deletedrow=0;
  int **temp=0;
  getAnswer(matrix,temp,dimsions,&answer,&deletedcol,&deletedrow);

  //printf("answer=%d\n",answer);
  printf("%d\n", answer);
}

void Matrix(FILE* f,int dimsions){
  int **matrix=calloc(dimsions,sizeof(int*));
  for (size_t i = 0; i < dimsions; i++) {
    matrix[i]=calloc(dimsions,sizeof(int*));
  }
  fill(f,matrix,dimsions);
  //read(matrix,dimsions);
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
