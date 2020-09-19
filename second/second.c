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

void InsertHere(int x,struct Node* node){
  struct Node * new;
  new = (struct Node *) malloc(sizeof(struct Node));
  new->num = x;
  new->next = node->next;
  node->next=new;
}

void Insert(int x){
  if (head==0) {
    head = calloc(1, sizeof(struct Node)); //allocate memory in the node as 0 (for num)
    head->num=x;
    return;
  }

  if (head->num>x) {
    struct Node * new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->num = x;
    new->next = head;
    head=new;
    return;
  }

  struct Node* current=head;

  while (current->next != 0){
    if(current->next->num>x) {
      InsertHere(x,current);
      return;
    }
    current = current->next;
  }

  current->next = calloc(1,sizeof(struct Node));
  current->next->num = x;
  current->next->next = 0;
}

void Delete(int x){ //should deal with an already sorted list
  if (head->num==x) {
    struct Node* temp=head;
    head=head->next;
    free(temp);
    return;
  }
  struct Node* current=head;
  while (current->next->num!=x) {
    current=current->next;
  }
  struct Node* temp=current->next;
  current->next=current->next->next;
  free(temp);


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
    int nextNum;
    /*
      could be swith statement here and the switch statement can have Ordered() without break
    */

    switch (content) {
      case "INSERT":
      printf("insert the next number\n");
    }

    /*
    if(strcmp(content,"INSERT")==0){
      fscanf(f,"%d",&nextNum);
      //printf("%d\n", nextNum);
      Insert(&nextNum);
    }

    if(strcmp(content,"DELETE")==0){
      printf("delete the next number\n");
      fscanf(f,"%d",&nextNum);
      //printf("%d\n", nextNum);
      Delete(&nextNum);
    }
    */


  }
  Insert(3);
  Insert(6);
  Insert(5);
  Insert(4);
  Insert(2);
  printf("\n");

  for(struct Node* current=head; current != 0; current=current->next){
    printf("%d ", current->num);
  }

  printf("\n");
  printf("head=%d\n", head->num);
  Delete(2);
  Insert(7);
  printf("\nNew: ");

  for(struct Node* current=head; current != 0; current=current->next){
    printf("%d ", current->num);
  }
  printf("\n");
  printf("head=%d\n", head->num);
  freeEverything(head);

  return EXIT_SUCCESS;
}
