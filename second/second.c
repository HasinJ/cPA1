#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

struct Node{
  int num;
  struct Node* next;
};

struct Node* head=0; //empty
struct Node* current=0; //empty


void Insert(int x){
  if (head==0) {
    head = calloc(1, sizeof(struct Node)); //allocate memory in the node as 0 (for num)
    head->num=x;
    return;
  }
  struct Node* temp=head;
  head=calloc(1,sizeof(struct Node));
  head->num=x;
  head->next=temp;


}

void Delete(int x){ //should deal with an already sorted list
  if (x==head->num) {
    struct Node* temp = head;
    printf("\n%d\n", temp->num);
  }
}

void freeEverything(struct Node* x){
  if (x==0) return;
  freeEverything(x->next);
  free(x);
  return;
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
    /*
      could be swith statement here and the switch statement can have Ordered() without break
    */
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
  Insert(1);
  Insert(2);
  Insert(3);
  for(struct Node* current=head; current != 0; current=current->next){
    printf("%d ", current->num);
  }
  printf("\n");
  //Delete(2);

  printf("head=%d\n", head->num);
  freeEverything(head);

  return EXIT_SUCCESS;
}
