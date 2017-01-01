#include"bits/stdc++.h"
using namespace std;
void union1(int src,int dst,int represent[],int v)
{
	int repofdst=represent[dst];
	for(int i=0;i<v;i++)
	{
		if(represent[i]==repofdst) represent[i]=represent[src];
	}
}
main()
{
	printf("Enter no. of nodes : ");
	int v;
	scanf("%d",&v);
	pair<int,pair<int,int> > graph[1000];
	int representative[v];
	for(int i=0;i<v;i++) representative[i]=i;

	printf("Enter connections(0 based) with weights\n-1 to terminate input\n\n");
	int src,dst,w;
	int ind=0;
	while(1)
	{
		scanf("%d",&src);
		if(src==-1) break;
		scanf("%d%d",&dst,&w);
		graph[ind++]=make_pair(w,make_pair(src,dst));
	}
	sort(graph,graph+ind);
	int ans=0;
	for(int i=0;i<ind;i++)
	{
		if(representative[graph[i].second.first]!=representative[graph[i].second.second])
		{
			ans+=graph[i].first;
			printf("%d%d ",graph[i].second.first,graph[i].second.second);
			union1(graph[i].second.first,graph[i].second.second,representative,v);
		}
	}
	printf("\n\n%d\n",ans);
}
