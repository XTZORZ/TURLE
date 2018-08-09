#include <fstream>
using namespace std;
struct node{
	int x;
	int y;
}f[1000][1000];
int n,m,c,x,y,tot;
int step[5][4]={{0,1},{1,0},{0,-1},{-1,0}};
int g[1000][1000];

ifstream cin("line.in");
ofstream cout("line.out");

node find(node a)
{
	if (a.x!=f[a.x][a.y].x||a.y!=f[a.x][a.y].y)
	{
		f[a.x][a.y]=find(f[a.x][a.y]);
		return f[a.x][a.y];
	}
	else return f[a.x][a.y];
}

void hebing(node a,node b)
{
	node a1=find(f[a.x][a.y]);
	node a2=find(f[b.x][b.y]);
	f[a1.x][a1.y]=f[a2.x][a2.y];
	return;
		
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) f[i][j].x=i,f[i][j].y=j;
	for (int i=1;i<=m;i++)
	{
		cin>>c>>x>>y; g[x][y]=++c;
		tot++;
		for (int i=0;i<4;i++)
		{
			int xx=x+step[i][0],yy=y+step[i][1];
			if (g[xx][yy]==g[x][y]) {
//				cout<<x<<" "<<xx<<endl; 
				node a1=find(f[x][y]);
				node a2=find(f[xx][yy]);
//				cout<<a1.x<<" "<<a1.y<<" "<<a2.x<<" "<<a2.y<<endl; 
				if (a1.x!=a2.x||a1.y!=a2.y) tot--,hebing(f[a1.x][a1.y],f[a2.x][a2.y]);
			}
		}cout<<tot<<endl;
	}
	return 0;
}

