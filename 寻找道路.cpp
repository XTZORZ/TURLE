#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct ed{
	int u;
	int nex;
}e[300000];
int n,m,x,y,d[300000],fir[20000],st,s,t;
bool v[20000],ok[20000],vis[20000];
void add(int u,int v)
{
	e[++st].u=u; e[st].nex=fir[v]; fir[v]=st;
}

void spfa(int b)  //最短路 
{
	memset(v,0,sizeof(v));
	memset(d,0x3f3f,sizeof(d));
	queue<int> q; q.push(b); v[b]=1; d[b]=0;
	while (!q.empty())
	{
		int k=q.front(); q.pop(); v[b]=0;
		for (int i=fir[k];i;i=e[i].nex)
		{
			int u=e[i].u,w=1;
			if (d[u]>d[k]+w&&ok[e[i].u]) {
				d[u]=d[k]+w;
				if (!v[u]) v[u]=1,q.push(u);
			}	
		}
	}
}

void bfs(int t)  //第一次的搜边 
{
	memset(v,0,sizeof(v));
	queue<int> q; q.push(t); ok[t]=v[t]=1;
	while (!q.empty())
	{
		int k=q.front(); q.pop();
		for (int i=fir[k];i;i=e[i].nex)
		if (!v[e[i].u]){
			int u=e[i].u; if (!v[u]) v[u]=1,ok[u]=1,q.push(u);
		}
	}
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>x>>y,add(x,y);
	cin>>s>>t; 
	bfs(t);
	for (int i=1;i<=n;i++) vis[i]=ok[i];
	for (int i=1;i<=n;i++) 
	if (!vis[i]) for (int j=fir[i];j;j=e[j].nex){
	if (ok[e[j].u]) ok[e[j].u]=0; 
	// 不能直接修改，有后效性。 
	}
	spfa(t);
	if (d[s]>=(0x3f3f)) cout<<"-1"<<endl;
	else cout<<d[s]<<endl;
}
