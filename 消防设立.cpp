#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct tr{
	int v;
	int next;
}tr[10000];
int ans,fir[10000],a,n,m,st,k,num[10000],d[10000],f[10000];
bool v[10000];
//map<int,int> num;
void add(int u,int v)
{
	tr[++st].v=u; tr[st].next=fir[v]; fir[v]=st;
	tr[++st].v=v; tr[st].next=fir[u]; fir[u]=st;

}
void qsort(int l,int r)
{
	int mid=(l+r)/2,i=l,j=r;
	while (i<=j)
	{
		while (d[i]>d[mid]) i++;
		while (d[j]<d[mid]) j--;
		if (i<=j)
		{
			swap(d[i],d[j]);
			swap(num[i],num[j]);
			swap(f[i],f[j]);
			i++; j--;
		}
	}
	if (i<r) qsort(i,r);
	if (l<j) qsort(l,j);
}
void dfs(int p,int fa)
{
//	cout<<num<<" "<<fa<<endl;
	d[p]=d[fa]+1; f[p]=fa;
	for (int i=fir[p];i>0;i=tr[i].next)
	if (tr[i].v!=fa) dfs(tr[i].v,p);
}
void search(int p,int dep)  //把<=2的点全干了 
{
//	if (v[p]) return;
	v[p]=1;  k--;
//	cout<<p<<" "<<dep<<endl;
	if (dep==2) return;
	for(int i=fir[p];i>0;i=tr[i].next)
	search(tr[i].v,dep+1);
	search(f[p],dep+1);
}
int main()
{
	cin>>n;
	for (int i=1;i<=n-1;i++)
	{
		cin>>a;
		add(a,i+1);
	}
	
	dfs(1,0);
	k=n;
	for (int i=1;i<=n;i++) num[i]=i;
//	for (int i=1;i<=n;i++) cout<<num[i]<<" "<<d[i]<<" "<<f[i]<<endl;
	while (true)
	{
		int t=0;
		for (int i=1;i<=n;i++)
		{
			if (!v[i]&&d[i]>d[t]) t=i;
		}
		if (t==0) break;
//		cout<<t<<endl;
		search(f[f[t]],0),v[t]=true,ans++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
7
1
1
2
2
4
6

*/
