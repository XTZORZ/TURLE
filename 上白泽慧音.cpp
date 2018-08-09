#include <iostream>
#include <stack>
using namespace std;
struct ed{
	int v;
	int next;
}e[100002];
int n,m,st,x,y,p,fir[100000];
int step,dnf[10000],low[10000],cnt,col[10000],ton[10000];
bool b[10000];
stack<int> q;

void add(int u,int v)
{
	e[++st].v=u; e[st].next=fir[v]; fir[v]=st;
}

void tarjan(int a)
{
	dnf[a]=low[a]=++step;
	q.push(a); b[a]=1;
	for (int i=fir[a];i>0;i=e[i].next)
	{
		int v=e[i].v;
		if (!dnf[v]) tarjan(v),low[a]=min(low[a],low[v]);
		else if (b[v]) low[a]=min(low[a],dnf[v]);
	}
	if (dnf[a]==low[a])
	{
		cnt++; int k=0;
		do{
			k=q.top(); q.pop();
			col[k]=cnt; b[k]=false; ton[cnt]++;
		}while(k!=a);
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>p;
		if (p==1) add(x,y);
		if (p==2) add(x,y),add(y,x);
	}
	for (int i=1;i<=n;i++)
	if (!dnf[i]) tarjan(i);
	int now=0;
	for (int i=1;i<=n;i++) if (ton[i]>ton[now]) now=i;
	cout<<ton[now]<<endl;
	for (int i=1;i<=n;i++) if (col[i]==now) cout<<i<<" ";
	return 0;
}
