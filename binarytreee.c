#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node*left;
   struct node*right;
   };
   
   struct node*createnode(int value){
      struct node*newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=value;
      newnode->left=newnode->right=NULL;
      return newnode;
      }
      
 struct node*insert(struct node*root,int value){
     if(root==NULL)
     return createnode(value);
     
     if(value<root->data)
       root->left=insert(root->left,value);
     else if (value>root->data)
       root->right=insert(root->right,value);
       
       return root;
  }
  void inorder(struct node*root){
     if(root !=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
        }
 }
 void preorder(struct node*root){
      if (root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
        }
   }
  void postorder(struct node*root){
      if (root==NULL)return;
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
        
   }
  
  struct node*search(struct node*root,int value){
      if(root==NULL || root->data==value)
         return root;
      if(value<root->data)
         return search(root->left,value);
      else
        return search(root->right,value);
 }
 
 struct node*findmin(struct node*node){
   while(node&&node->left!=NULL)
      node=node->left;
   return node;
   }
   
   struct node*deletenode(struct node*root,int value){
     if (root==NULL)
        return root;
     if(value < root->data)
        root->left=deletenode(root->left,value);
     else if (value>root->data)
        root->right=deletenode(root->right,value);
     else {
       if (root->left==NULL){
          struct node*temp=root->right;
          free(root);
          return temp;
          }else if (root->right==NULL){
          struct node*temp=root->left;
          free(root);
          return temp;
          }
          
  struct node*temp=findmin
  (root->right);
  root->data=temp->data;
  root->right=deletenode(root->right,temp->data);
  }
  return root;
  }
  
  int main(){
    struct node*root=NULL;
    int choice,value;
    
    while(1){
       printf("\nbinary search tree menu:\n");
       printf("1.insert\n2.inorder traversal\n3.preorder traversal\n4.postorder traversal\n5.search\n6.delete\n7.exit\n");
       printf("enter your choice:");
       scanf("%d",&choice);
       
       switch(choice){
          case 1:
             printf("enter value to insert:");
             scanf("%d",&value);
             root=insert(root,value);
             break;
             
          case 2:
             printf("inorder traversal:");
             inorder(root);
             printf("\n");
             break;
          case 3:
             printf("preorder traversal:");
             preorder(root);
             printf("\n");
             break;
          case 4:
             printf("postorder traversal:");
             postorder(root);
             printf("\n");
             break;
          case 5:
             printf("enter value to search:");
             scanf("%d",&value);
             if(search(root,value))
                printf("value%d found in BST.\n",value);
             else
                printf("value%d not found in BST.\n",value);
             break;
          case 6:
             printf("enter value to delete:");
             scanf("%d",&value);
             root=deletenode(root,value);
             break;
          case 7:
             printf("exiting....\n");
             exit(0);
             
          default:
             printf("invalid choice.try again.\n");
             }
      }
      return 0;
      }
         
             
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
      
