#include<stdio.h>
#include<limits.h>
#define MAX 100

int main(){
    int n,i,j;
    int cost[MAX][MAX];
    int visited [MAX];
    int no_of_edges=0;
    int total_cost=0;
    printf("enter no.of.vertices: ");
    scanf("%d",&n);
    printf("enter cost adjecency matrix(enter 0 if no edges):\n");
    for(i=0; i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
             cost[i][j]= INT_MAX;
        }
    }
        for(i=0;i<n;i++)
           visited[i]=0;
        visited[0]=1;
    printf("\n edges in minimum cost spanning tree:\n");
    while(no_of_edges<n-1){
       int min=INT_MAX;
       int u=-1,v=-1;
       
        for(i=0;i<n;i++){
            if (visited[i]){
                for(j=0;j<n;j++){
                    if(!visited[j]&&cost[i][j]<min){
                       min=cost[i][j];
                       u=i;
                       v=j;
                   } 
               }
            }
        }
    if(u!=-1 && v!=-1){
    printf("%d-> %d=%d\n",u+1,v+1,cost[u][v]);
    visited[v]=1;
    total_cost+= cost[u][v];
    no_of_edges++;
    }else{
    break;
    }
    }
    printf("\n minimum cost= %d\n",total_cost);
    return 0;  
}
