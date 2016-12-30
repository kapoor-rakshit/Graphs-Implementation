#include"bits/stdc++.h"
using namespace std;
int wt[1000][1000];
bool visited[1000]= {false};
main()
{
    int v;
    printf("Enter no. of vertices : ");
    scanf("%d",&v);
    vector<int> graph[v];
    printf("Enter connections(0 based) with their weights\n-1 to terminate input\n\n");
    int src,dst,w;
    while(1)
    {
        scanf("%d",&src);
        if(src==-1) break;
        scanf("%d%d",&dst,&w);
        graph[src].push_back(dst);
        wt[src][dst]=w;
    }

    int distance[v];
    for(int i=0; i<v; i++) distance[i]=INT_MAX;
    int tempdistance[v];
    for(int i=0; i<v; i++) tempdistance[i]=INT_MAX;
    int parent[v];
    for(int i=0; i<v; i++) parent[i]=-1;
    printf("Enter source : ");
    int start;
    scanf("%d",&start);
    tempdistance[start]=0;

    for(int i=1; i<=v; i++)
    {
        int mn=INT_MAX;
        int ind=-1;
        for(int j=0; j<v; j++)                                                    //extract min
        {
            if(visited[j]==false&&tempdistance[j]<mn)
            {
                mn=tempdistance[j];
                ind=j;
            }
        }
        if(ind!=-1)
        {
            visited[ind]=true;                                                  //contains
            distance[ind]=tempdistance[ind];
            for(int j=0; j<graph[ind].size(); j++)
            {
                if(distance[ind]+wt[ind][graph[ind][j]]<tempdistance[graph[ind][j]]&&visited[graph[ind][j]]==false)
                {
                    tempdistance[graph[ind][j]]=distance[ind]+wt[ind][graph[ind][j]];         //decrease key
                    parent[graph[ind][j]]=ind;                                               //add key
                }
            }
        }
    }
    printf("Parents of vertices are\n");
    for(int i=0;i<v;i++) printf("%d ",parent[i]);
    printf("\n");
    printf("Shortest distance are\n");
    for(int i=0;i<v;i++) if(distance[i]==INT_MAX) printf("Unaccesible "); else printf("%d ",distance[i]);
    printf("\n\n");
}
