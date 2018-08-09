#include <iostream>
#include <stack>
using namespace std;
struct node{
	int v;
	int next;
}ed[60000];
int dnf[20000],low[20000],fir[20000],ansp,ans,x,y,n,m,step,cnt,col[20000];
bool b[20000];
int du[20000],ton[20000];
stack<int> q;

void add(int a,int b,int num)
{
	ed[num].v=b; ed[num].next=fir[a]; fir[a]=num;
}//ÒÔb°®a 

void tarjan(int x)
{
	dnf[x]=low[x]=++step;
	b[x]=true; q.push(x);
	for (int i=fir[x];i>0;i=ed[i].next)
	{
		int v=ed[i].v;
		if (!dnf[v]) tarjan(v),low[x]=min(low[x],low[v]);
		else if (b[v]) low[x]=min(low[x],low[v]);
	} 
	if (dnf[x]==low[x])
	{
		cnt++; //if(x==3) cout<<cnt<<"!!"<<endl;
		col[x]=cnt; b[x]=false;
		while (q.top()!=x)
		{
			int k=q.top(); q.pop();
			col[k]=cnt; b[k]=false;
		} q.pop();
	}
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>x>>y,add(x,y,i);
	for (int i=1;i<=n;i++)
	if (!dnf[i]) tarjan(i);
//	for (int i=1;i<=n;i++) cout<<col[i]<<" ";
	for (int i=1;i<=n;i++)
	{
		for (int j=fir[i];j>0;j=ed[j].next)
		{
			int v=ed[j].v;
		//	cout<<i<<" "<<v<<endl;
			
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=fir[i];j>0;j=ed[j].next)
		{
			int v=ed[j].v;
			if (col[i]!=col[v]) du[col[i]]++;
			
		}
		ton[col[i]]++;
	}
//	cout<<cnt<<endl;
	ans=0;
	for (int i=1;i<=cnt;i++) {if (du[i]==0&&ans) {cout<<"0"<<endl; return 0;}
	if (du[i]==0) ans=ton[i];
	} 
	cout<<ans<<endl;
	return 0;
}

