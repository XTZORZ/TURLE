#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
struct tr{
	int u;
	int w;
	int next;
}t[60000];
struct ed{
	int w;
	int x;
	int y;
}e[60000];
int n,m,x,y,z,st,q;
int fa[20000],fir[20000],f[20000][20],d[20000],g[20000];
//~~~~~~~~~~~~~KRU
int find(int f)
{
	if (f!=fa[f]) return fa[f]=find(fa[f]);
	else return fa[f];
}

void add(int x,int y,int z)
{
	e[++st].x=x; e[st].y=y; e[st].w=z;
}

void adde(int u,int v,int w)
{
	t[++st].u=u; t[st].w=w; t[st].next=fir[v]; fir[v]=st;
	t[++st].u=v; t[st].w=w; t[st].next=fir[u]; fir[u]=st;
}
bool cmp(ed a,ed b)
{
	return a.w>b.w; 
}
//~~~~~~~~~~~~~~~~
void dfs(int u,int fa)
{
//	cout<<"!!!"<<u<<"!"<<fa<<endl;
	d[u]=d[fa]+1; f[u][0]=fa;
	for (int i=1;(1<<i)<=d[u];i++) f[u][i]=f[f[u][i-1]][i-1];
	for (int i=fir[u];i;i=t[i].next)
	if (t[i].u!=fa) {
		g[t[i].u]=t[i].w;
		dfs(t[i].u,u);
	}
}

int lca(int a,int b)
{
	if (d[a]>d[b]) swap(a,b);
	for (int i=13;i>=0;i--) if (d[b]-(1<<i)>=d[a]) b=f[b][i];
	if (a==b) return a;
	
	for (int i=13;i>=0;i--)
	if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	return f[a][0];
}

int main()
{
	cin>>n>>m; 
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++) cin>>x>>y>>z,add(x,y,z);
	st=0; int sum=0;
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++)
	{
		if (find(e[i].x)!=find(e[i].y))
		{
			int f1=find(e[i].x),f2=find(e[i].y);
			fa[f1]=f2; sum++;
			adde(e[i].x,e[i].y,e[i].w);
		}
		if (sum==n-1) break;
	}
	for (int i=1;i<=n;i++) if (!f[i][0]) dfs(i,0);
	//可能不连通！！！ 
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>x>>y; int dd=lca(x,y),l=INT_MAX/2,r=INT_MAX/2;
		for (int i=x;i!=dd;i=f[i][0]) l=min(l,g[i]);
		for (int i=y;i!=dd;i=f[i][0]) r=min(r,g[i]);
	//把所在的链跑一边 
//		cout<<dd<<"!"<<endl;
		if (!l&&!r) cout<<"-1"<<endl;
		else cout<<min(l,r)<<endl;
	}
	return 0;
}
