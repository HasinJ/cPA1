#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct Node{
  int num;
  struct Node* next;
};

struct Node* head=0; //empty

void Pop(){
  if(head==0) return;
  struct Node* temp = head;
  head=head->next;
  free(temp);
  return;
}

void Push(int x){
  if (head==0){
    head = calloc(1,sizeof(struct Node));
    head->num=x;
    return;
  }
  struct Node* new = (struct Node*) malloc(sizeof(struct Node));
  new->num=x;
  new->next=head;
  head=new;
}

void Enqueue(int x){
  if(head==0) {
    Push(x);
    return;
  }
  struct Node* current=head;
  while(current->next!=0){
    current=current->next;
  }
  current->next = calloc(1,sizeof(struct Node));
  current->next->num = x;
  current->next->next = 0;
}

int main(int argc, char *argv[argc+1]) {

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
  while (fscanf(f,"%s",content)!=EOF) {
    int num;
    if(strcmp(content,"PUSH")==0){
      fscanf(f,"%d",&num);
      Push(num);
    }else{
      if (strcmp(content,"POP")==0) {
        Pop();
      }else{
        if (strcmp(content,"ENQUEUE")==0) {
          fscanf(f,"%d",&num);
          Enqueue(num);
        }
      }
    }

    for(struct Node* current=head; current != 0; current=current->next){
      printf("%d ", current->num);
    }
    if(head==0) printf("EMPTY\n");
    else printf("\n");
  }

  /*
  Push(1);
  Push(2);
  Pop();
  for(struct Node* current=head; current!=0; current=current->next){ //can be used in second.c
    printf("%d ", current->num);
  }
  printf("head=%d\n", head->num);
  printf("\n");

  Enqueue(3);
  for(struct Node* current=head; current!=0; current=current->next){ //can be used in second.c
    printf("%d ", current->num);
  }
  printf("head=%d\n", head->num);
  printf("\n");
  */

  return EXIT_SUCCESS;
}
