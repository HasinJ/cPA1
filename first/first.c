#include<stdio.h>
#include<stdlib.h>


int prime(int x){
  for (size_t i = 2; i <= x/2; i++) {
    if(x%i==0) return 0; //isnt a prime
  }
  return 1; //is a prime
}

int main(int argc, char* argv[argc +1]) {
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

  char content[10];
  while (fscanf(f,"%[^\n]\n",content) != EOF ) {
    int number=atoi(content);

    if(number==1 || number==0){
      printf("no\n");
      continue;
    }

    if(prime(number)==1){ //if the number is prime
      (prime(number+2)==1 || prime(number-2)==1) ? printf("yes\n"):printf("no\n"); //figuring out twin prime
    }
    else printf("no\n"); //if the number isn't prime

  }

}
