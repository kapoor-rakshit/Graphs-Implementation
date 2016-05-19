#include<bits/stdc++.h>
using namespace std;
main()
{
    printf("Enter no. of nodes\n");
    int n;
    scanf("%d",&n);
    vector<int> graph[n+1];
    queue<int> q;
    printf("Enter no. of edges and connections\n");
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        graph[l].push_back(r);
    }

    printf("Enter root to start traversal from\n");
    int start;
    scanf("%d",&start);

    bool visited[1000]={false};

    q.push(start);
    while(q.empty()==false)
    {
        int front_element=q.front();
        q.pop();

        if(visited[front_element]==false)
        {
            visited[front_element]=true;
            printf("%d ",front_element);

            for(int i=0;i<graph[front_element].size();i++)
                q.push(graph[front_element][i]);
        }
    }
}

