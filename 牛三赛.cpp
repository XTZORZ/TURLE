#include <iostream>
#include <climits>
using namespace std;
int x,y,g[200][200],tot,ans[200],n,m;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) g[i][j]=INT_MAX/2;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y; g[x][y]=1;
	}
	for (int k=1;k<=n;k++)	
	for(int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (g[i][j]<INT_MAX/2) ans[i]++,ans[j]++;
	for (int i=1;i<=n;i++)
	if (ans[i]==n-1) tot++;
	cout<<tot<<endl;
	return 0;
}
