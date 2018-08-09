#include <iostream>
using namespace std;
int tree[300001]={0},x,y,n,m,a,b;
char c;

void pushup(int o)
{
	tree[o]=tree[o*2]+tree[o*2+1];
	return;
}

void build(int o,int l,int r)
{
	if (l==r) 
	{
		tree[o]=0;	return;
	}
	int mid=(l+r)/2;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
	pushup(o);
	return;
} 

void add(int o,int l,int r,int x,int k)
{
	if (l==r) {
		tree[o]+=k;	return;
	}
	if (x<l||x>r) return;
	int mid=(l+r)/2;
	if (x<=mid) add(o*2,l,mid,x,k);
	else add(o*2+1,mid+1,r,x,k);
	pushup(o);
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
	build(1,1,n);
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>c>>a>>b;
		if (c=='x') add(1,1,n,a,b);
		if (c=='y') cout<<query(1,1,n,a,b)<<endl;
	}
	return 0;
} 
