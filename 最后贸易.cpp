#include <iostream>
#include <queue>
using namespace std;
struct node{
	int v;
	int next;
}edge[1000000];
int fir[100000],n,m,x,y,z,a[100000];
int d1[100000],d2[100000],st;   //d1--min, d2--max
bool b[100000];

void ax_spfa(int be)
{
	memset(b,0,sizeof(b));
	queue<int> q;
	b[be]=true; 
}
void add(int x,int y,int s)
{
	edge[i].v=x; edge[i].next=fir[y]; fir[y]=s;
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if (z==1) add(x,y,++st);
		if (z==2) add(x,y,++st),add(y,x,++st); 
	}
	ax_spfa(1);
	in_spfa(1);
}
