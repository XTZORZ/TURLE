#include <iostream>
#include <queue>
#include <climits>
using namespace std;
struct ed{
	int v;
	int w;
	int next;
}e[4000001];
int d[2000001],f[2000001],ans[2000001],jiyi[2000001],n,m,x,y,en;
bool v[2000001];

void add(int a,int b)
{
	e[++en].v=b; e[en].w=1; e[en].next=f[a];
	f[a]=en;
}

int dfs(int a)
{
	if (jiyi[a]!=0) return jiyi[a];
	for (int i=f[a];i>0;i=e[i].next) 
	{
		int v=e[i].v;
		if (d[v]==d[a]-1) jiyi[a]=(jiyi[a]+dfs(v))%100003;
	}
	return jiyi[a];
}

void spfa(int b)
{
	for (int i=1;i<=n;i++) d[i]=INT_MAX/2,v[i]=false;
	d[b]=0; v[b]=true;
	queue<int> q; q.push(b);
	while (!q.empty())
	{
		int k=q.front(); q.pop(); v[k]=false;
		for (int i=f[k];i>0;i=e[i].next)
		{
			int vv=e[i].v,w=e[i].w;
			if (d[k]+w<d[vv])
			{
				d[vv]=d[k]+w; if (!v[vv]) v[vv]=true,q.push(vv);
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) 
	{
		cin>>x>>y;
		add(x,y); add(y,x);
	}
	spfa(1);
	jiyi[1]=1;
	for (int i=1;i<=n;i++) cout<<dfs(i)<<endl;
	return 0;
}
