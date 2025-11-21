#include<stdio.h>
#define MAX 32
void inputset(int set[],int n){
    int i,x,m;
    for(i=0;i<n;i++)set[i]=0;
    printf("enter number of the elements in the set:");
    scanf("%d",&m);
    printf("enter %d elements(between 0 and %d):\n",m,n-1);
    for (i=0; i<m; i++){
      scanf("%d", &x);
      if(x>=0 && x<n)
      set[x]=1;
    else
      printf("invalid element%d! ignored.\n",x);
      }
}
  
void displayset(int set[],int n){
     int i, empty =1;
     printf("{");
     for(i=0;i<n;i++){
       if (set[i]==1){
        printf(" %d ",i);
        empty =0;
        }
     }
 if (empty)printf("{}");
    printf("}\n");
}
       
void unionset(int A[],int B[],int C[],int n){
    for (int i=0; i<n;i++)
    C[i]=A[i]|B[i];
    }
void intersectionset(int A[],int B[],int C[],int n){
    for (int i=0; i<n;i++)
    C[i]=A[i]&B[i];  
    }
void differencesetAB(int A[],int B[],int C[],int n){
    for (int i=0; i<n;i++)
    C[i]= A[i]&(!B[i]); 
    }
void differencesetBA(int A[],int B[],int C[],int n){
    for (int i=0; i<n;i++)
    C[i]= B[i]&(!A[i]); 
    }

int main(){
  int A[MAX],B[MAX],C[MAX];
  int n,choice;
   printf("enter size of universal set(max%d):",MAX);
   scanf("%d",&n);
    printf("\n                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       enter set A:\n");
    inputset(A,n);
     
    printf("\nenter set B:\n");
    inputset(B,n);
  
  do {
     printf("\n---MENU---\n");
     printf("1.display sets\n");
     printf("2.union(AUB)\n");
     printf("3.intersection(AnB)\n");
     printf("4.difference(A-B)\n");
     printf("5.difference(B-A)\n");
     printf("6.exit\n");
     printf("enter your choice:");
     scanf("%d",&choice);
     
     
     switch (choice){
        case 1:
           printf("\nset A=");
           displayset(A,n);
           printf("set B=");
           displayset(B,n);
           break;
        case 2:
           unionset(A,B,C,n);
           printf("\n AUB=");
           displayset(C,n);
           break;
        case 3:
           intersectionset(A,B,C,n);
           printf("\n AnB=");
           displayset(C,n);
           break;
        case 4:
           differencesetAB(A,B,C,n);
           printf("\n A-B=");
           displayset(C,n);
           break;
        case 5:
           differencesetBA(A,B,C,n);
           printf("\n B-A=");
           displayset(C,n);
           break;
        case 6:
           printf("\nexiting program.\n");
           break;
        default:
           printf("invalid choice! try again.\n");
      }
    } while (choice!=6);
    return 0;
}





