#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
struct edge{
	int v;
	int w;
	int next;
	
}e[2000000];
int st,n,m,x,y,k,s,ans,a[2000],rd[2000],d[2000],fir[2000];
bool qwq,v[2000],g[2001][2001];
queue<int> q;
void add(int x,int y)
{
	e[++st].v=x; e[st].next=fir[y]; fir[y]=st;
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) 
	{
		memset(v,0,sizeof(v));
		cin>>s;
		for (int j=1;j<=s;j++) cin>>a[j],v[a[j]]=1;
		for (int j=a[1];j<=a[s];j++)
			if (!v[j]) for (int k=1;k<=s;k++) if(!g[a[k]][j]) add(j,a[k]),g[a[k]][j]=true,rd[j]++;
	}
	for (int i=1;i<=n;i++) if (!rd[i]) q.push(i);
	while (!q.empty())
	{
		int k=q.front(); q.pop(); 
		for (int i=fir[k];i>0;i=e[i].next)
		{
			int v=e[i].v;
			rd[v]--;  d[v]=d[k]+1,ans=max(ans,d[v]);
			if (!rd[v]) q.push(v);
		}
	}
//	for (int i=1;i<=n;i++) cout<<rd[i]<<" "<<d[i]<<endl;
//	for (int i=1;i<=n;i++) ans=max(ans,d[i]);
	cout<<ans+1<<endl;
	return 0;
}
