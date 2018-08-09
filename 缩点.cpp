#include <iostream>
#include <climits>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;
struct node{
	int v;
	int next;
}ed[2000000];
int dnf[200000],low[200000],col[200000],cnt,step;
int ans,st,n,m,x[200000],y[200000],va[200000],ton[200000],fir[200000];
int f[200000];
bool b[200000];
stack<int> s;
void add(int x,int y,int num)
{
	ed[num].v=x; ed[num].next=fir[y]; fir[y]=num;
}

void tarjan(int p)
{
	dnf[p]=low[p]=++step;
	b[p]=true; s.push(p);
	for (int i=fir[p];i>0;i=ed[i].next)
	{
		int v=ed[i].v;
		if (!dnf[v]) tarjan(v),low[p]=min(low[p],low[v]);
		else if (b[v]) low[p]=min(low[p],low[v]);
	}
	if (dnf[p]==low[p])
	{
		cnt++; int k;
		do
		{
			k=s.top(); s.pop();
			col[k]=cnt; ton[cnt]+=va[k];
			b[k]=false;
		} while (k!=p);
	}
}

int search(int a)
{
	if (f[a]) return f[a];
	f[a]=ton[a]; int k=0;
	for (int i=fir[a];i>0;i=ed[i].next)
	if (!b[ed[i].v])
	{	b[ed[i].v]=true;
		k=max(k,search(ed[i].v));
		b[ed[i].v]=false;
	}
	f[a]+=k;
	return f[a];
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) fir[i]=-1;
	for (int i=1;i<=n;i++) cin>>va[i];
	for (int i=1;i<=m;i++) cin>>x[i]>>y[i],add(x[i],y[i],i);
	for (int i=1;i<=n;i++) if (!dnf[i]) tarjan(i);//tarjan
//	for (int i=1;i<=n;i++) cout<<col[i]<<" ";cout<<endl;
//	for (int i=1;i<=cnt;i++)cout<<ton[i]<<" ";
	if (cnt==1) {
		cout<<ton[1]<<endl; return 0;
	}
	for (int i=1;i<=n;i++) fir[i]=-1;
	memset(b,0,sizeof(b));
	for (int i=1;i<=m;i++) if (col[x[i]]!=col[y[i]]) add(col[y[i]],col[x[i]],++st);
	//cout<<endl;
	for (int i=1;i<=cnt;i++) ans=max(ans,search(i));
	cout<<ans<<endl;
	return 0; 
}
/* 6 8
1 3 2 2 2 3
1 2
1 3
2 4
3 4
3 5
4 1
4 6
5 6*/
