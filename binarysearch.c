#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
   int data;
   struct node*left,*right;
 };
 
 
 struct node*root=NULL;
 struct node*createnode (int data){
 struct node*newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=data;
     newnode->left=newnode->right=NULL;
     return newnode;
     }
   struct node*findnode(struct node*node,int key){
   if (node==NULL) return NULL;
   if (node->data==key) return node;
   
   struct node*found=findnode(node->left,key);
   if(found) return found;
   return findnode(node->right,key);
   }
   
  void insertnode(int parentval,int childval,char side){
  if(root==NULL){
  root=createnode(childval);
  printf("tree was empty.created root=%d\n",childval);
     return;
     }
     struct node*parent=findnode(root,parentval);
     if(!parent){
     printf("parent node %d not found!\n",parentval);
     return;
     }
     if(side=='L'||side=='l'){
     if(parent->left==NULL){
       parent->left=createnode(childval);
     }else{
        printf("left child al;ready exists for %d!\n", parentval);
        }
     }else if (side=='R'||side=='r'){
        if (parent->right==NULL){
        parent->right=createnode(childval);
     }else{
        printf("right child already exists for %d!\n", parentval);
        }
     }else{
        printf("invalid choice! use L or R.\n");
        }
    }
     struct node*deletenode(struct node*node,int key){
     if (node==NULL) return NULL;
     if(node->data==key){
     if(node->left) deletenode(node->left,node->left->data);
     if(node->right) deletenode(node->right,node->right->data);
     free(node);
     return NULL;
     }
     node->left=deletenode(node->left,key);
     node->right=deletenode(node->right,key);
     return node;
     }
     
     void inorder(struct node*node){
     if(node){
       inorder(node->left);
       printf("%d",node->data);
       inorder(node->right);
       }
  }
  
  void preorder(struct node*node){
    if(node){
    printf("%d",node->data);
    preorder(node->left);
    preorder(node->right);
     }
  }
   void postorder(struct node*node){
     if (node){
     postorder(node->left);
     postorder(node->right);
     printf("%d",node->data);
     }
 }
 
 int main(){
   int choice,parentval,childval,delval;
   char side;
   
   do{
     printf("\n---binary tree menu---\n");
     printf("1.insert node\n");
     printf("2. delete a node(and its subtree)\n");
     printf("3.inorder traversal\n");
     printf("4. preorder traversal\n");
     printf("5.postorder traversal\n");
     printf("6. exit\n");
     printf("enter choice:");
     scanf("%d",&choice);
     
    switch(choice){
      case 1:
        if(root==NULL){
        printf("enter root value");
        scanf("%d",&childval);
        root=createnode(childval);
     }else{
        printf("enter parent value:");
        scanf("%d",&parentval);
        printf("enter childvalue:");
        scanf("%d",&childval);
        printf("insert left or right of %d?(L/R):",parentval);
        scanf("%c",&side);
        insertnode(parentval,childval,side);
        }
        break;
        
        case 2:
         if (root==NULL){
           printf("tree is empty!\n");
         }else{
           printf("enter node value to delete:");
           scanf("%d",&delval);
           root=deletenode(root,delval);
           }
           break;
           
           case 3:
             printf("inorder:");
             inorder(root);
             printf("\n");
             break;
             case 4:
               printf("preorder:");
             preorder(root);
             printf("\n");
             break;
          case 5:
             printf("posteorder:");
             postorder(root);
             printf("\n");
             break;
          case 6:
            printf("exiting...\n");
            break;
            
          default:
            printf("invalid choice!\n");
            }
         }while(choice!=6);
         
         return 0;
         }
      
      
      
      
     
     
     
     
     
     
     
     
     
     
     
        
       
       
       
       
       
       
       
       
       
       
       
        
        
        
        
        
        
        
        
        
     
  
