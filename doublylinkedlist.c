#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node*prev;
   struct node*next;
   };
 struct node*head=NULL;
 struct node*tail=NULL;
 
 void insertatbeginning(int value){
   struct node*newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=value;
     newnode->prev=NULL;
     newnode->next=head;
     
     
     if(head==NULL)
     tail=newnode;
   else
     head->prev=newnode;
     
   head=newnode;
   }
 void insertatend(int value){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
     newnode->next=NULL;
     newnode->prev=tail;
     
   if(tail==NULL)
     head=newnode;
   else
     tail->next=newnode;
     
     tail=newnode;
     }
  void deletefrombeginning(){
    if(head==NULL){
     printf("list is empty.\n");
     return;
  }
  struct node*temp=head;
  head=head->next;
  
  if(head!=NULL)
     head->prev=NULL;
  else
     tail=NULL;
     
   free(temp);
   printf("deleted from beginning.\n");
 }
 void deletefromend(){
 if(tail==NULL){
   printf("list is empty.\n");
   return;
   }
   struct node*temp=tail;
   tail=tail->prev;
   
   if(tail!=NULL)
     tail->next=NULL;
  else
    head=NULL;
    
    free(temp);
    printf("deleted from end.\n");
}

void traversefrombeginning(){
    struct node*temp=head;
    if(temp==NULL){
    printf("list is empty.\n");
    return;
    }
    printf("list(from beginning):");
    while (temp!=NULL){
      printf("%d",temp->data);
      temp=temp->next;
      }
      printf("\n");
      }
      
void traversefromend(){
   struct node*temp=tail;
    if(temp==NULL){
    printf("list is empty.\n");
    return;
    }
    
    printf("list(from end):");
    while (temp!=NULL){
      printf("%d",temp->data);
      temp=temp->prev;
      }
      printf("\n");
      }
void countelements(){
   struct node*temp=head;
   int count=0;
   while(temp!=NULL){
   count++;
   temp=temp->next;
 }
 printf("number of elements:%d\n",count);
 }
 int main(){
   int choice,value;
   while(1){
     printf("\n---doubly linked list menu---\n");
     printf("1. insert at beginning\n");
     printf("2.insert at end\n");
     printf("3.delete from beginning\n");
     printf("4.delete from end\n");
     printf("5.traverse from beginning\n");
     printf("6.traverse from end\n");
     printf("7.count elements\n");
     printf("8.exit\n");
     printf("enter your choice:");
     scanf("%d",&choice);
     
     switch (choice){
       case 1:
         printf("enter value:");
         scanf("%d",&value);
         insertatbeginning(value);
         break;
       case 2:
         printf("enter value:");
         scanf("%d",&value);
         insertatend(value);
         break;
       case 3:
         deletefrombeginning();
         break;
       case 4:
         deletefromend();
         break;
       case 5:
         traversefrombeginning();
         break;
       case 6:
         traversefromend();
         break;
       case 7:
          countelements();
          break;
       case 8:
          printf("exiting...\n");
      }
 }
 return 0;
 }












   
   
   
   
   
   
   
   
   
   
   
   
   
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
     
