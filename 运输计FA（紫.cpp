#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct tr{
	int u;
	int w;
	int next;
}tr[700000];
using namespace std;
int a,b,t,m,n,maxx,ff[300001],u[300001],v[300001],l[300001],fir[300001],p[300001],tot[300001];
int st,dep[300001],dis[300001],d[300001],f[300001][26];

void add(int u,int v,int w)
{
	tr[++st].u=u; tr[st].w=w; tr[st].next=fir[v]; fir[v]=st;
	tr[++st].u=v; tr[st].w=w; tr[st].next=fir[u]; fir[u]=st;
}

void dfs(int u,int fa)
{
	f[u][0]=fa; p[++st]=u;
	for (int i=1;(1<<i)<=dep[u];i++)
	f[u][i]=f[f[u][i-1]][i-1];
	for (int i=fir[u];i>0;i=tr[i].next)
	{
		int v=tr[i].u,w=tr[i].w;
		if (v!=fa)
		{
			dep[v]=dep[u]+1; dis[v]=dis[u]+w;
			tot[v]=w; //边上权值 
			dfs(v,u);	
		}
	}
}

int lca(int a,int b)
{
	if (dep[a]>dep[b]) swap(a,b);
	for (int i=19;i>=0;i--)
	if (dep[a]<=dep[b]-(1<<i)) b=f[b][i];
//	cout<<a<<" "<<b<<endl;
	if (b==a) return a;
	for (int i=19;i>=0;i--)	if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	return f[a][0];
}

bool check(int k)
{
	memset(ff,0,sizeof(ff));
	int cnt=0;
	for (int i=1;i<=m;i++)
	if (d[i]>k) {
		ff[u[i]]++,ff[v[i]]++,ff[l[i]]-=2;  //一个枝干断成两链，分别差分 
		cnt++;
	}
	for (int i=n;i>=1;i--)
	{
		ff[f[p[i]][0]]+=ff[p[i]]; //把标记上移到爸爸那里，向上推进 
		if (tot[p[i]]>=maxx-k&&ff[p[i]]==cnt)return true;
	}
	return false; 
}
int erfen(int l,int r)
{
	int mid=0;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)fir[i]=-1; 
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&a,&b,&t);
		add(a,b,t);
	}
	dep[1]=1; dis[1]=0; st=0; dep[0]=-1;
	dfs(1,0);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		l[i]=lca(u[i],v[i]);
	//	cout<<u[i]<<" "<<v[i]<<" "<<l[i]<<endl;
		d[i]=dis[u[i]]+dis[v[i]]-2*dis[l[i]];
		//if (i==2) cout<<l[i]<<" "<<u[i]<<" "<<v[i]<<endl;
		maxx=max(maxx,d[i]);
	}
	//cout<<maxx<<endl;
	//for (int i=1;i<=n;i++) printf("%d %d %d\n",dep[i],dis[i],l[i]);  	
	printf("%d",erfen(0,maxx+1));
	return 0;
}
