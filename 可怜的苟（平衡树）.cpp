#include <iostream>
#include <algorithm>
using namespace std;
int w[9000000],l[9000000],r[9000000],rt[9000000];
int n,m,a[4000000],b[4000000],x,y,k,cnt;

int build(int ll,int rr)
{
	int ro=++cnt;
	if (ll!=rr)
	{
		int mid=(ll+rr)/2;
		l[ro]=build(ll,mid);
		r[ro]=build(mid+1,rr);
	}
	return ro;
}

int add(int pre,int ll,int rr,int x)
{
	int ro=++cnt;
	w[ro]=w[pre]+1; l[ro]=l[pre]; r[ro]=r[pre];
	if (ll!=rr)
	{
		int mid=(ll+rr)/2;
		if (x<=mid) l[ro]=add(l[pre],ll,mid,x);  //更新左子树 
		else r[ro]=add(r[pre],mid+1,rr,x);  //更新右子树 
	}
	return ro;
 } 

int query(int ro1,int ro2,int ll,int rr,int k)
{
	int x=w[l[ro2]]-w[l[ro1]];
	if (ll!=rr)
	{
		int mid=(ll+rr)/2;
		if (k<=x) return query(l[ro1],l[ro2],ll,mid,k); //k与x关系???
		else return query(r[ro1],r[ro2],mid+1,rr,k-x); //每次都汪 
	}
	return ll;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i]; b[i]=a[i];
	}
	sort(a+1,a+n+1);
	int l=unique(a+1,a+n+1)-(a+1);
	rt[0]=build(1,l);
	for (int i=1;i<=n;i++)
	{
		int t=lower_bound(a+1,a+l+1,b[i])-a;
		rt[i]=add(rt[i-1],1,l,t);
	}
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>k;
		int t=query(rt[x-1],rt[y],1,l,k);
		cout<<a[t]<<endl;
	}
	return 0;
}
