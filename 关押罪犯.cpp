#include<iostream>
#include <algorithm>
using namespace std;
struct edge{
	int a;
	int b;
	int c;
}ed[200030];
int n,m;
int f[60000];

bool cmp(edge a,edge b)
{
	return a.c>b.c;
}

int find(int a)
{
	if (a!=f[a]) return f[a]=find(f[a]);
	else return f[a];
}
void he(int a,int b)
{
	int f1=find(a),f2=find(b);
	f[f1]=f2;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>ed[i].a>>ed[i].b>>ed[i].c; 
	}
	sort(ed+1,ed+m+1,cmp);
	for (int i=1;i<=2*n;i++) f[i]=i;
	for (int i=1;i<=m+1;i++)
	{
		int f1=find(ed[i].a),f2=find(ed[i].b);
//		cout<<f1<<" "<<f2<<endl;
		if (f1!=f2) he(ed[i].a,ed[i].b+n),he(ed[i].b,ed[i].a+n);
		else 
		{ cout<<ed[i].c<<endl; return 0;}
	}
	cout<<0<<endl;
	return 0;
}
