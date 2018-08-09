#include <iostream>
#include <stack>
using namespace std;
struct node{
	int c;
	int u;
}p[1000];
struct edge{
	int v;
	int w;
	int next;
	
}e[100000];
int n,m,x,y,k,rd[1000],cd[1000],fir[1000];
bool qwq;
stack<int> q;
void add(int x,int y,int w,int n)
{
	e[n].v=x; e[n].next=fir[y]; fir[y]=n; 
	e[n].w=w;
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>p[i].c>>p[i].u;
	for (int i=1;i<=m;i++) cin>>x>>y>>k,add(y,x,k,i),rd[y]++,cd[x]++;
	for (int i=1;i<=n;i++) if (!rd[i]) q.push(i);
	while (!q.empty())
	{
		int k=q.top(); q.pop(); 
		if (p[k].c>0) for (int i=fir[k];i>0;i=e[i].next)
		{
			int v=e[i].v,w=e[i].w;
			rd[v]--; p[v].c+=w*p[k].c;
			if (!rd[v]) q.push(v),p[v].c-=p[v].u;
		}
	}
	for (int i=1;i<=n;i++) if (!cd[i]&&p[i].c>0) qwq=1,cout<<i<<" "<<p[i].c<<endl;
	if (!qwq) cout<<"NULL"<<endl;
	return 0;
}
