#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;

void insert(int val){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=top;
    top=newnode;
    printf("%d inserted\n",val);
}

void deletenode(){
    if (top==NULL) {
        printf("Stack Empty!\n");
        return;
    }
    struct node *temp=top;
    printf("%d deleted\n",temp->data);
    top=top->next;
    free(temp);
}

void display() {
    if (top==NULL) {
        printf("Stack Empty!\n");
        return;
    }
    struct node *temp=top;
    printf("Stack elements: ");
    while (temp!=NULL) {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void count(){
    if (top==NULL) {
        printf("Stack Empty!\n");
        return;
    }
    int c=0;
    struct node *temp=top;
    while (temp!=NULL) {
        c++;
        temp=temp->next;
    }
    printf("Total number of nodes=%d\n",c);
}

int main() {
    int val,ch;
    while (1) {
        printf("---Singly Linked Stack Menu---\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Display\n");
        printf("4.Count\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                insert(val);
                break;
            case 2:
                deletenode();
                break;
            case 3:
                display();
                break;
            case 4: 
                count();break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!");
            }
           }
       return 0;
     }

