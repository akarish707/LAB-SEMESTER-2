#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct Node{
    int num;
    char name[255];
    char title[255];
    struct Node* next;
} *head, *tail,*prev;

void Display();
void pushTail();
void popHead();
//int count();
void del();
typedef struct Node n;
int no;
char nama[255], judul[255];
char p;



void Display(){
    int count = 0;
    //if(!head){
      //  return;
    //}
    n*curr = head;
    //for(Node*curr = head; curr!=NULL; curr = curr ->next){

    //}
    //printf("===== List =====\n");
    while(curr!=0){
        if(count>0)
        printf("\n");
        printf("Number of List : %d\n ", curr->num);
        printf("Name          : %s\n ", curr->name);
        printf("Book Title    : %s\n ", curr->title);
        count++;
        curr = curr->next;
    } 
       if(count==0){
        printf("\n---There Are No List Available---\n");
        }
    return count;
}

/*n *createNode(int num, const char* name, const char* title) {
  printf("Number of List :\n"); scanf("%d", &no);
  printf("Name           :\n");scanf("%s",&nama);
  printf("Book Title     :\n"); scanf("%s",&judul);
  n*newNode = (n*)malloc(sizeof(n)); 
  newNode->num = no;
  strcpy(newNode->name,nama);
  strcpy(newNode->title,judul);
  newNode->next = NULL;
  return newNode;
}*/

//kalau butuh insert depan
void pushHead() {
    
  printf("Input Number of List : "); scanf(" %d", &no);
  printf("Input Name           : ");scanf(" %s",&nama);
  printf("Input Book Title     : "); scanf(" %s",&judul);
  n*newNode = (n*)malloc(sizeof(n)); 
  newNode->num = no;
  strcpy(newNode->name,nama);
  strcpy(newNode->title,judul);
  newNode->next = NULL; 

  if(!head) { 
    head = tail = newNode;
  } else { 
    newNode->next = head; 
    head = newNode; // nodenya jadi head
  }
}

void pushTail() {
    
  //n *temp = createNode;
  //error char
  //temp->name = nama;
  //temp->title = judul;
  printf("Input Number of List : "); scanf(" %d", &no);
  printf("Input Name           : ");scanf(" %[^\n]",&nama);
  printf("Input Book Title     : "); scanf(" %[^\n]",&judul);
  n*newNode = (n*)malloc(sizeof(n)); 
  newNode->num = no;
  strcpy(newNode->name,nama);
  strcpy(newNode->title,judul);
  newNode->next = NULL;
  if(!head){
        head = tail = newNode;
    }else{
        tail->next = newNode; //node menunjuk ke head yg baru
        tail = newNode; //node akan menjadi head yang baru
    }
}

void popHead() {
  
  if(!head) { // empty list
    printf("\n---There are no list available---\n");
  }else if(head == tail) { 
    free(head); // free allocated memory
    head = tail = NULL; 
    printf("\n---Borrowing Has Been Sucessfull---\n");
  } else  { 
    n *temp = head->next;
    head->next = NULL; 
    free(head); 
    head = temp; 
    printf("\n---Borrowing Has Been Sucessfull---\n");
  }

}

//buat index kalau disuruh
/*void deleteNode() 
{ 

   int pos, i;
   Display();
   
   // If linked list is empty 
   if (head == NULL){ 
      //printf("\n---There are no list available---\n");
      return; 
   } else{
     printf("\nInput the number you want to delete : \n");
     scanf("%d", &pos);
     // Store head node 
   n* temp = head; 
  
    // If head needs to be removed 
    if (pos == 1) 
    { 
        head = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for (i=1; temp!=NULL && i<pos-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of nodes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct Node *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list
    printf("\nDeleted Successfully \n\n");

   }
  
        
} */

void del(){
  int pos;
  Display();
   
   // If linked list is empty 
   if (head == NULL){ 
      //printf("\n---There are no list available---\n");
      return; 
   } else{
     printf("\nInput the number you want to delete : \n");
     scanf("%d", &pos);
     n* temp = head; 
     if(temp->num == pos){
       head=temp->next;
       free(temp);
       printf("\nDeleted Successfully \n\n");
     }else{
       while(temp!=NULL){
         if(temp->num==pos){
           prev->next = temp->next;
           free(temp);
           printf("\nDeleted Successfully \n\n");
           break;
         } else{
           prev = temp;
           temp = temp->next;
         }
       }
     }
}
}

int main(){
    int option = 0;

    while (option < 5) {
    printf("===========================\n");
    printf("\nSt. Joseph Lending Library\n");
    printf("\n===========================\n");
    printf("[1] View Borrower List \n");
    printf("[2] New Borrower List \n");
    printf("[3] Service\n");
    printf("[4] Delete Borrower List\n");
    printf("[5] Exit\n");
    printf("Input Your Choice >> "); scanf("%d", &option);
    switch (option) {
      case 1:
        Display();
        printf("\n");
        system("PAUSE");
        system("CLEAR || CLS");
        break;
      case 2:
        pushTail();
        printf("\n");
        system("PAUSE");
        system("CLEAR || CLS");
        break;
      case 3:
        popHead();
        printf("\n");
        system("PAUSE");
        system("CLEAR || CLS");
        break;
      case 4:
        del();
        system("PAUSE");
        system("CLEAR || CLS");
        break;
      default:
        break;
    }
  }

  return 0;
}
