#include <iostream>
#include <algorithm>
using namespace std;
struct ed{
	int l;
	int r;
	int w;
}e[300000];
bool b[10000];
int n,m,x,y,z,ans,p,f[10000];

int find(int a)
{
	if (f[a]==a) return f[a];
	else f[a]=find(f[a]);
}
bool cmp(ed a,ed b)
{
	return a.w<b.w;
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++){
		cin>>x>>y>>z;
		e[i].l=x,e[i].r=y,e[i].w=z;
	}
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++)
	if (p!=n-1)
	{
		int ll=find(e[i].l),rr=find(e[i].r);
		if (ll!=rr) 
		{
			f[ll]=rr; ans+=e[i].w; p++;
		} 
	}
	if (p!=n-1) cout<<"orz"<<endl;
	else cout<<ans<<endl;
}
