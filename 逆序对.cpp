#include <iostream>
#include <algorithm>
using namespace std;
struct jing{
	int v,n;
}a[100021];
long long n,ha[100001]={0},tree[400001]={0},ans=0;

bool cmp(jing a,jing b)
{
	return (a.v<b.v)?true:false;
}

void add(int o,int l,int r,int x)
{
	if (l==r)
	{
		tree[o]+=1;	return;
	}
	if (x<l||x>r) return;
	int mid=(l+r)/2;
	if (x<=mid) add(o*2,l,mid,x);
	if (x>mid) add(o*2+1,mid+1,r,x);
	tree[o]=tree[o*2]+tree[o*2+1];
	return;
}

int query(int o,int l,int r,int x,int y)
{
	if (y<l||x>r) return 0;
	if (x<=l&&r<=y) return tree[o];
	int mid=(l+r)/2;
	return query(o*2,l,mid,x,y)+query(o*2+1,mid+1,r,x,y);
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i].v; a[i].n=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) ha[a[i].n]=i;
	for (int i=n;i>=1;i--)
	{
		add(1,1,n,ha[i]);
		ans+=query(1,1,n,1,ha[i])-1;
	}
	cout<<ans<<endl;
	return 0;
}
