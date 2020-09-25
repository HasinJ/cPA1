#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

struct Element{
  int num;
  struct Element* next;
};

struct Element* first=0;



void freeEverything(struct Element* x){
  if (x->next==0) return;
  struct Element* temp = x;
  x=x->next;
  free(temp);
  freeEverything(x);
  return;
}

void Matrix(FILE* f,int dimsions){

  struct Element* current=0;
  for (size_t i = 0; i < dimsions; i++) {
    current = calloc(1,sizeof(struct Element));
    for (size_t j = 0; j < dimsions; j++) {
      fscanf(f,"%d\t",&current->num);
      //current->row = i;
      //current->col = j;
      current->next = 0;
      if(first==0) first=current;
      printf("current:%d\n", current->num);
      current=current->next;
    }
  }


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

  printf("\n");
  return EXIT_SUCCESS;
}
