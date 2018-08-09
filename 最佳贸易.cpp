#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
struct node{
	int v;
	int next;
}edge[1000000],edge1[1000000];
int fir[100000],fir1[100000],n,m,x,y,z,a[100000];
int d1[100000],d2[100000],st,ss,ans;   //d1--min, d2--max
bool b[100000];

void in_spfa(int be)
{
	memset(b,0,sizeof(b));
	queue<int> q;
	for (int i=1;i<=n;i++) d1[i]=INT_MAX/2;
	b[be]=true; q.push(be); d1[be]=a[be];
	while (!q.empty())
	{
		int k=q.front(); q.pop(); b[k]=0;
		for (int i=fir[k];i>0;i=edge[i].next)
		{
			
			int v=edge[i].v; 
//			cout<<v<<" : "<<d1[k]<<" , "<<a[v]<<endl;
			if (min(a[v],d1[k])<d1[v])
			{
				d1[v]=min(a[v],d1[k]);
				if (!b[v]) {
					q.push(v); b[v]=true;
				}
			}
		}
	}
	return;
}

void ax_spfa(int be)
{
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++) d2[i]=0;
	d2[be]=a[be];
	queue<int> q1;
	b[be]=true; q1.push(be);
	while (!q1.empty())
	{
		int k=q1.front(); q1.pop(); b[k]=0;
//	cout<<k<<endl;	
	for (int i=fir1[k];i>0;i=edge1[i].next)
		{
			int v=edge1[i].v;
//			cout<<d2[k]<<" "<<a[v]<<endl;
			if (d2[v]<max(a[v],d2[k]))
			{
				d2[v]=max(a[v],d2[k]);
				if (!b[v]) {
					q1.push(v); b[v]=true;
				}	
			}
			
		}
	}
	return ;
}

void add(int x,int y)
{
	edge[++st].v=x; edge[st].next=fir[y]; fir[y]=st;
}

void add1(int x,int y)
{
	edge1[++ss].v=x; edge1[ss].next=fir1[y]; fir1[y]=ss;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) fir[i]=fir1[i]=-1;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if (z==1) add(y,x),add1(x,y);
		if (z==2) {
			add(x,y),add1(y,x);
			add(y,x),add1(x,y); 
		}
	}
	in_spfa(1);
	ax_spfa(n);	
	for (int i=1;i<=n;i++) cout<<d1[i]<<" "<<d2[i]<<endl,ans=max(ans,d2[i]-d1[i]);
	cout<<ans<<endl;
	return 0;
}
