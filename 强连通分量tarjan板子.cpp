#include<iostream>
#include<stack>
using namespace std;
struct node{
	int v;
	int next;
}g[60000];
int fir[20000],dnf[20000],low[20000],step,cnt,n,m,a,b,col[20000],ans;
int ton[10001];
stack<int> q;
bool v[20000];

void add(int a,int b,int nu)
{
	g[nu].v=a; g[nu].next=fir[b]; fir[b]=nu;
}

void tarjan(int ii)
{
	dnf[ii]=low[ii]=++step;
	v[ii]=true;
	q.push(ii);
	for (int i=fir[ii];i>0;i=g[i].next)
	{
		int b=g[i].v;
		if (!v[b]) tarjan(b),low[ii]=min(low[b],low[ii]);
		else low[ii]=min(low[b],low[ii]);
	}
	if (dnf[ii]==low[ii])
	{
		cnt++;
		col[ii]=cnt; v[ii]=false; ton[cnt]++;
		while (q.top()!=ii)
		{
			int k=q.top(); q.pop();
			col[k]=cnt; v[k]=false;
			ton[cnt]++;
		} q.pop();
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>a>>b;
		add(a,b,i);
	}
	for (int i=1;i<=n;i++)
	if (!dnf[i]) tarjan(i);
//	cout<<cnt<<endl;
	for (int i=1;i<=10000;i++) if (ton[i]>1) ans++;
	cout<<ans<<endl;
	return 0;
}
