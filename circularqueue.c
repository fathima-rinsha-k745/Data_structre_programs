#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int front=-1,rear=-1;

int isfull(){
return ((front==0 && rear==SIZE-1)||(front==rear+1));
}
 int isempty(){
   return (front==-1);
 }
 
 void enqueue(int value){
   if (isfull()){
     printf("queue is full! cannot insert %d\n",value);
       return;
       }
     if(front==-1)
     front=0;
   rear=(rear+1)% SIZE;
   queue[rear]=value;
   printf("%d inserted\n",value);
  }
 void dequeue(){
   if (isempty()){
     printf("queue is empty! cannot delete\n");
     return;
    }
    printf("%d deleted\n",queue[front]);
    if (front==rear){
    front=rear=-1;
    }else{
      front=(front+1)% SIZE;
      }
 }
 
 void display(){
   if(isempty()){
     printf("queue is empty!\n");
     return;
     }
     printf("queue elements:");
     int i=front;


     while(1){
       printf("%d  ",queue[i]);
       if (i==rear)
         break;
      i=(i+1)% SIZE;
    }
    printf("\n");
  }
  
  int count(){
    if (isempty())
    return 0;
   if (rear>=front)
     return rear-front+1;
   else
     return SIZE-front+rear+1;
}

int main(){
   int choice,value;
   while(1){
     printf("\n---circular queue menu---\n");
     printf("1. insert(enqueue)\n");
     printf("2. delete(dequeue)\n");
     printf("3. display\n");
     printf("4. count elements\n");
     printf("5. exit\n");
     printf("enter your choice:");
     scanf("%d",&choice);
     
     switch(choice){
     case 1:
        printf("enter value to insert:");
        scanf("%d",&value);
        enqueue(value);
        break;
     case 2:
        dequeue();
        break;
     case 3:
        display();
        break;
     case 4:
        printf("number of elements=%d\n",count());
        break;
     case 5:
        exit(0);
      default:
        printf("invalid choice!\n");
       }
     }
     return 0;
} 
     
     
     
     
     
     
     
     
     
     












      
       
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
   

