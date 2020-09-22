
int** read(FILE* f,int dimsions) {
  fscanf(f,"%d",dimsions);
  int** matrix=calloc(dimsions,size(int*));//rows
  for (int i=0; i<dimsions; i++){
    matrix[i]=calloc(dimsions,size(int*));//columns
  }
  for (size_t i = 0; i < dimsions; i++) {
    for (size_t j = 0; j < dimsions; j++) {
      &matrix[i,j]
    }
  }


}

int main(int argc, char *argv[]) {
  if (argc>2 || argc==1) {
    printf("Please enter 1 file name.\n");
    return EXIT_SUCCESS;
  }

  FILE *f;
  f = fopen(argv[1],"r");
  if (f==0) {
    printf("error.\n");
    return EXIT_SUCCESS;

  int x=atoi(argv[2]);
  //checks for even/odd
  if ((x/2)!=((x-1)/2)) read(f,x);
  else printf("error.\n");
  return EXIT_SUCCESS;

  }

}
