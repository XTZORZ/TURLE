#include<iostream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
int p[2000][2000],ji[2000][2000],v[2000][2000],n,m,l,r,mid,ans=INT_MAX/2;
bool ok=1;
int go[4][4]={{0,1},{0,-1},{1,0},{-1,0}};

bool yuejie(int x,int y)
{
	return (x>0&&x<=n&&y>0&&y<=m);
}

bool check(int a)
{
	memset(v,0,sizeof(v)); int st=m;
	queue<int> fx,fy; v[1][1]=1;
	fx.push(1),fy.push(1); 
	while (!fx.empty()&&st!=0)
	{
		int x1=fx.front(),y1=fy.front();
//		cout<<x1<<" "<<y1<<endl;
		fx.pop(),fy.pop(); 
		for (int i=0;i<4;i++)
		{
			int x=x1+go[i][0],y=y1+go[i][1];
			if (x==n&&!v[x][y]) return 1;
			else if (yuejie(x,y)&&!v[x][y]&&p[x][y]<=a) fx.push(x),fy.push(y),v[x][y]=1;
		}
	}
	return 0;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) cin>>p[i][j],r=max(r,p[i][j]);
	while (l<r)
	{
		mid=(l+r)/2; ok=1;
		if (check(mid)) r=mid,ans=min(ans,r);
		else l=mid+1;
//		cout<<mid<<"!"<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
