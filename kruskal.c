#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct edge{
     int u,v,w;
};
int parent[MAX];
int find(int i){
    while(parent[i]!=i)
      i=parent[i];
    return i;
}
void union_sets(int i,int j){
    int a=find(i);
    int b=find(j);
    parent[a]=b;
}
int main(){
    struct edge edges[MAX];
    int n,e;
    int i,j,u,v,w;
    int mincost=0;

    printf("enter number of vertices: ");
    scanf("%d",&n);
    printf("enter number of edges: ");
    scanf("%d",&e);

    printf("enter edges(u v w):\n");
    for(i=0;i<e;i++){
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
    }
    for(i=0;i<n;i++)
     parent[i]=i;

    for(i=0;i<e-i-1;i++){
        for(j=0;j<e-i-1;j++){
            if(edges[j].w>edges[j+1].w){
                struct edge temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;

            }
        }

    }
    printf("\nedges in the minimum spanning tree:\n");

    int count=0;
    for(i=0;i<e && count<n-1;i++){
      u=edges[i].u;
      v=edges[i].v;
      w=edges[i].w;
      
      if (find(u)!=find(v)){
        printf("%d-%d:%d\n",u,v,w);
        mincost+=w;
        union_sets(u,v);
        count++;
      }
    }
    printf("\nminimum cost=%d\n",mincost);
    return 0;
    
}
