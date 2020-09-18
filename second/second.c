#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
  int i;
  struct Node* next;
}

struct Node *head=0;

void Insert(int x){
  if (head==0) {
    head = calloc(1, sizeof(struct Node));
    head->i=x;
  }
}

int main(int argc, char *argv[argc+1]) {
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

  char content[10];
  while (fscanf(f,"%s",content) != EOF ) {
    int temp;

    if(strcmp(content,"INSERT")==0){
      printf("insert the next number\n");
      fscanf(f,"%d",&temp);
      printf("%d\n", temp);
    }

    if(strcmp(content,"DELETE")==0){
      printf("delete the next number\n");
      fscanf(f,"%d",&temp);
      printf("%d\n", temp);

    }

  }

  return EXIT_SUCCESS;
}
