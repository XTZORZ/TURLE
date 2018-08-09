#include <iostream>
using namespace std;
struct tree{
	int v;
	int next;
}t[10000];
int n,x,y,dep,fir[10000],st;
int f[10000][30],d[10000];
long long ans1,ans2,w[10000];

void add(int u,int v)
{
	t[++st].v=u; t[st].next=fir[v]; fir[v]=st;
	t[++st].v=v; t[st].next=fir[u]; fir[u]=st;
}

void dfs(int s,int fa)
{
	f[s][0]=fa; d[s]=d[fa]+1;
	for (int i=1;(1<<i)<=d[s];i++)
	f[s][i]=f[f[s][i-1]][i-1];
	for (int i=fir[s];i>0;i=t[i].next)
	{
		int v=t[i].v;
		if (v!=fa) dfs(v,s);
	}
}

int lca(int a,int b)
{
	if (d[a]>d[b]) swap(a,b);
	for(int i=20;i>=0;i--)
	if (d[a]<=d[b]-(1<<i)) b=f[b][i];  //small,then climb
	if (a==b) return a;
	for (int i=20;i>=0;i--)
	if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	return f[a][0];
}
int main()
{
	cin>>n;
	for (int i=1;i<=n-1;i++)
	cin>>x>>y,add(x,y);
	for (int i=1;i<=n;i++)cin>>w[i];
	dfs(1,0);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (i!=j)
	{
		int k=lca(i,j);
		dep=d[i]+d[j]-2*d[k];
		if (dep==2) {
			ans1=(ans%10007+w[i]*w[j]%10007)%10007;
			ans2=max(ans2,w[i]*w[j]);
		}
	}
	cout<<ans2<<" "<<ans1<<endl; 
	return 0;
}
