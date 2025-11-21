#include<stdio.h>
#define MAX 100
   int parent[MAX];
   int rankarr[MAX];
   int n;

void createset(int n){
   for(int i=0; i<n;i++){
     parent[i]=i;
     rankarr[i]=0;
     }
     printf("\ncreated %d disjoint sets(0 to %d)\n",n,n-1);
     }
     
int findset(int x){
    if (parent[x]!=x)
        parent[x]=findset(parent[x]);
    return parent[x];
    }
    
void unionset(int x,int y){
   int root x=findset(x);
   int root y=findset(y);
   if(root x==root y){
      printf("\nelements %d and%d are already in the same set.\n",x,y);
      return;
      }
    if
    
     
     
     
     
     
     
     
     
     
     
     
     
     
