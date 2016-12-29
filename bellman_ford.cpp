#include"bits/stdc++.h"
using namespace std;
int wt[1000][1000];
main()
{
    int v;
    printf("Enter no. of vertices\n");
    scanf("%d",&v);
    int parent[v];
    for(int i=0; i<v; i++) parent[i]=-1;
    int distance[v];
    for(int i=0; i<v; i++) distance[i]=INT_MAX;
    vector<int> graph[v];
    printf("Enter connections with their weights\n-1 to terminate input\n\n");
    while(1)
    {
        int src,dst,w;
        scanf("%d",&src);
        if(src==-1) break;

        scanf("%d%d",&dst,&w);
        graph[src].push_back(dst);
        wt[src][dst]=w;
    }
    printf("Enter source\n");
    int start;
    scanf("%d",&start);
    distance[start]=0;

    for(int i=1; i<=v-1; i++)                                                            //relax func called v-1 times
    {
        for(int j=0; j<v; j++)
        {
            for(int k=0; k<graph[j].size(); k++)
            {
                if(distance[j]!=INT_MAX){
                if(distance[j]+wt[j][graph[j][k]]<distance[graph[j][k]])             //distance of source + weight[src][dst]<distance[destination]
                {
                    distance[graph[j][k]]=distance[j]+wt[j][graph[j][k]];           //distance is modified
                    parent[graph[j][k]]=j;                                          //parent becomes source of edge
                }
                }
            }
        }
    }
    int flg=0;
    for(int j=0; j<v; j++)                                                     //relax func called vth time to check -ve wt cycle
    {
        for(int k=0; k<graph[j].size(); k++)
        {
            if(distance[j]!=INT_MAX){
            if(distance[j]+wt[j][graph[j][k]]<distance[graph[j][k]])
            {
                flg=1;
                break;
            }
            }
        }
        if(flg==1) break;
    }
    if(flg==1) printf("Negative weight cycle detected\n");
    else
    {
        printf("Parents of vertices are\n");
        for(int i=0;i<v;i++) printf("%d ",parent[i]);
        printf("\n\n");
        printf("Shortest distances of vertices from source\n");
        for(int i=0;i<v;i++) if(distance[i]==INT_MAX) printf("Unaccessible "); else printf("%d ",distance[i]);
        printf("\n");
    }
}
