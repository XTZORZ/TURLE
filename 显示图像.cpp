#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,m,f[2000][2000];
bool g[2000][2000],u[2000][2000];
int goo[5][3]={{0,1},{0,-1},{1,0},{-1,0}};
queue<int> fx,fy,ans;
bool yuejie(int x,int y)
{
	return (x>0&&x<=n&&y>0&&y<=m);
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		char c;
		cin>>c;
		if (c=='0') g[i][j]=1;
		else g[i][j]=0,fx.push(i),fy.push(j),ans.push(0),u[i][j]=1;
		f[i][j]=100000;
	}
	while (!fx.empty())
	{
		int x=fx.front(),y=fy.front(),k=ans.front();
//		cout<<x<<" "<<y<<" "<<k<<endl;
		fx.pop(),fy.pop(),ans.pop();
	//	u[x][y]=0;
		f[x][y]=min(f[x][y],k);
		for (int i=0;i<4;i++)
		{
			int xx=x+goo[i][0],yy=y+goo[i][1];
			if (yuejie(xx,yy)&&g[xx][yy]&&!u[xx][yy])
			{
				u[xx][yy]=1;
//				cout<<xx<<" "<<yy<<" "<<k+1<<endl;
				fx.push(xx),fy.push(yy),ans.push(k+1);
			}
		 } 
	}
	for (int i=1;i<=n;i++){
	for (int j=1;j<=m;j++)
	cout<<f[i][j]<<" ";
	cout<<endl;
	}
}

