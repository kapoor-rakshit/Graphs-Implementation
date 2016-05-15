#include<bits/stdc++.h>
using namespace std;
bool a[1000][1000];
int wt[1000][1000];
main()
{
    int n,m;
    printf("Enter no. of nodes\n");
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            a[i][j]=false;
            wt[i][j]=INT_MAX;
        }
    }

    printf("Enter no. of connections and the connections with weight\n");
    scanf("%d",&m);

    for(int i=1; i<=m; i++)
    {
        int l,r,w;
        scanf("%d%d%d",&l,&r,&w);
        a[l][r]=true;
        wt[l][r]=w;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
            {
                a[j][k]=a[j][k]||(a[j][i]&&a[i][k]);
                if(wt[j][i]!=INT_MAX&&wt[i][k]!=INT_MAX)
                wt[j][k]=min(wt[j][k],wt[j][i]+wt[i][k]);
            }
printf("\nPath Matrix is:-\n");
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i][j]) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
printf("\nWeight Matrix is:-\n");
for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(wt[i][j]!=INT_MAX) printf("%d ",wt[i][j]);
            else printf("oo ");
        }
        printf("\n");
    }
}
