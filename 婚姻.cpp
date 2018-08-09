#include <iostream>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
struct node{
	int v;
	int next;
	bool used;
}ed[300000];
int n,m,st,fir[100000];
int dnf[100000],low[100000],col[100000],step,cnt,ans;
stack<int> s; 
string s1,s2;
map<string,int> ma; 
bool b[100000];

void add(int u,int v,int num)
{
	ed[num].v=u; ed[num].next=fir[v]; fir[v]=num;
}
void tarjan(int a)
{
	dnf[a]=low[a]=++step;
	s.push(a); b[a]=true;
	for (int i=fir[a];i>0;i=ed[i].next)
	if (!ed[i].used)
	{
		int v=ed[i].v;
		if (!dnf[v]) tarjan(v),low[a]=min(low[a],low[v]);
		else if (b[v]) low[a]=min(low[a],dnf[v]); 
	}
	if (dnf[a]==low[a])
	{
		cnt++; int k=0;
		do 
		{
			k=s.top(); s.pop();
			b[k]=false; col[k]=cnt;
		} while (k!=a);
	}
}

int main()
{
	cin>>n; n*=2; 
	//for (int i=1;i<=n;i++) fir[i]=-1;
	for (int i=1;i<=n;i+=2) 
	{
		cin>>s1>>s2;
		ma[s1]=i; ma[s2]=i+1;
		add(i,i+1,++st);
	}
	cin>>m; 
	for (int i=n+1;i<=n+m;i++) 
	{
		cin>>s1>>s2;
		int a=ma[s1],b=ma[s2];
		add(b,a,++st);
	}
//	for (int i=1;i<=n;i+=2) 
//	for (int j=fir[i];j;j=ed[j].next) cout<<i<<" "<<ed[j].v<<endl;
	for (int i=1;i<=n;i++) if (!dnf[i]) tarjan(i);
//	cout<<cnt<<endl;
	ans=cnt;
//	for (int i=1;i<=n;i++) cout<<i<<" "<<col[i]<<endl; 
	for (int i=1;i<=n;i+=2)
	{
		if (col[i]==col[i+1]) cout<<"Unsafe"<<endl;
		else cout<<"Safe"<<endl;
	}
	return 0;
}
