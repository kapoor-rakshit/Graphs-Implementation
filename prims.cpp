#include"bits/stdc++.h"
using namespace std;
vector<int> graph[3005];
int vande[3005];                                 //store vertex(v) and which edge(e) contributed that min edge
int wt[3005][3005];
main()
{
    int v,e;
    scanf("%d%d",&v,&e);
    int distance[v+1];
    bool visited[v+1];

    for(int i=1; i<=v; i++) distance[i]=INT_MAX;
    for(int i=1; i<=v; i++) visited[i]=false;

    for(int i=1; i<=v; i++)
        for(int j=1; j<=v; j++)
            wt[i][j]=-1;

    for(int i=0; i<e; i++)
    {
        int src,dst,w;
        scanf("%d%d%d",&src,&dst,&w);
        if(wt[src][dst]!=-1)                           //check if multiple edges b/w same nodes
        {
            wt[src][dst]=min(wt[src][dst],w);
            wt[dst][src]=min(wt[dst][src],w);
        }
        else
        {
            wt[src][dst]=w;
            wt[dst][src]=w;
        }
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    int start;
    scanf("%d",&start);
    distance[start]=0;

    int gs=graph[start].size();
    for(int i=0; i<gs; i++)                 //source is the first extract min
    {
        if(visited[graph[start][i]]==false&&wt[start][graph[start][i]]<distance[graph[start][i]])  //contains
        {
            distance[graph[start][i]]=wt[start][graph[start][i]];                                 //decrease key
            vande[graph[start][i]]=start;                                                        //add key
        }
    }
    visited[start]=true;
    int ans=0;
    for(int i=0; i<v-1; i++)
    {
        int mn=INT_MAX;
        int ind;
        for(int j=1; j<=v; j++)
            if(visited[j]==false&&distance[j]<mn)            //contains, extract min
            {
                mn=distance[j];
                ind=j;
            }
        printf("%d%d ",vande[ind],ind);                     //edge which made this min is in answer
        gs=graph[ind].size();
        for(int j=0; j<gs; j++)
        {
            if(visited[graph[ind][j]]==false&&wt[ind][graph[ind][j]]<distance[graph[ind][j]])  //contains
            {
                distance[graph[ind][j]]=wt[ind][graph[ind][j]];                               //decrease key
                vande[graph[ind][j]]=ind;                                                     //add key
            }
        }
        visited[ind]=true;
    }
    for(int i=1;i<=v;i++) ans+=distance[i];
    printf("\n%d",ans);
}
