#include<algorithm>
#include <iostream>
using namespace std;
struct ed{
	int v;
	int w;
	int next;
}e[2000000];
int fir[20000],fa[20000],n,m,x,y,z,q,st;

bool cmp(ed a,ed b)
{
	return (a.w>b.w);
}

void add(int u,int v,int w)
{
	e[++st].v=v; e[st].w=w; e[st].next=fir[u];
	fir[u]=st;
	e[++st].v=u; e[st].w=w; e[st].next=fir[v];
	fir[v]=st;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		add(x,y,z);
	}
	int now=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+st+1,cmp);
	while (now<n)
	{
		
	}
	return 0; 
}

