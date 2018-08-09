#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
int g[20][20],n,m,r,c,ans=INT_MAX,minn;
int ha[20],w[20][20],f[20][20];//以j为结束的选i个列最小 
int abs(int a)
{
	return (a>0)?a:-a;
}

void dpl()
{
	memset(w,0,sizeof w);
	memset(f,127,sizeof f);
	for (int i=1;i<=m;i++)
	for (int j=i+1;j<=m;j++)
	for (int k=1;k<=r;k++)
	{
		w[i][j]+=abs(g[ha[k]][i]-g[ha[k]][j]);
	}
	for (int i=1;i<=m;i++)
	{
		f[1][i]=0;
		for (int k=2;k<=r;k++)
		f[1][i]+=abs(g[ha[k]][i]-g[ha[k-1]][i]);
	}
	
	for (int i=2;i<=c;i++)
	for (int j=i;j<=m;j++)
	for (int k=0;k<j;k++)
	{
		f[i][j]=min(f[i][j],f[i-1][k]+w[k][j]+f[1][j]);
	}
	for (int i=c;i<=m;i++)
	ans=min(ans,f[c][i]);
}
void dfsh(int h,int now)
{
	if (h==r+1)
	{
		dpl();
	}
	else
	{
		for (int i=now;i<=n;i++) 
		{
			ha[h]=i; 
			dfsh(h+1,i+1);
			//		for (int i=1;i<=r;i++)
		//	cout<<ha[i]<<" "; cout<<now<<endl;
		}
	}
	return;
}


int main()
{
	cin>>n>>m>>r>>c;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)	cin>>g[i][j];
	dfsh(1,1);
	cout<<ans<<endl;
	return 0;
}
