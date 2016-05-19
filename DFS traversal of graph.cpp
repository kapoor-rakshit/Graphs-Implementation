#include<bits/stdc++.h>
using namespace std;
main()
{
    printf("Enter no. of nodes\n");
    int n;
    scanf("%d",&n);
    vector<int> graph[n+1];
    stack<int> s;
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

    s.push(start);
    while(s.empty()==false)
    {
        int top_element=s.top();
        s.pop();

        if(visited[top_element]==false)
        {
            visited[top_element]=true;
            printf("%d ",top_element);

            for(int i=0;i<graph[top_element].size();i++)
                s.push(graph[top_element][i]);
        }
    }
}
