#include <iostream>
using namespace std;

int n,m,x,y,p;
long long k,ans;
int a[100001]={0},addv[500000]={0};
long long tree[500000]={0};
void pushup(int o)
{
	tree[o]=tree[o*2]+tree[o*2+1];
	return;
}
void build(int o,int l,int r) //小有建树
{
	addv[o]=0;
	if (l==r) 
	{
		tree[o]=a[l]; return;
	}
	int mid=(l+r)/2;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
	pushup(o);
	return;
}

void pushdown(int o,int l,int r)  //此处可修改 
{
	if (!addv[o]) return;
	int mid=(l+r)/2;
	tree[o*2]+=addv[o]*(mid-l+1); addv[o*2]+=addv[o];
	tree[o*2+1]+=addv[o]*(r-mid); addv[o*2+1]+=addv[o];
	addv[o]=0;
	return;
}

void add(int o,int l,int r,int x,int y,long long k)  //区间的 
{
	if (x<=l&&r<=y) 
	{
		addv[o]+=k; tree[o]+=k*(r-l+1);
		return;
	}
	if (y<l||x>r) return;
	int mid=(l+r)/2;
	pushdown(o,l,r);
	add(o*2,l,mid,x,y,k);
	add(o*2+1,mid+1,r,x,y,k);
	pushup(o);
	return;
}

long long query(int o,int l,int r,int x,int y)
{
	if (y<l||x>r) return 0;
	if (x<=l&&r<=y) return tree[o];
	int mid=(l+r)/2;
	pushdown(o,l,r); ans=0;
	return query(2*o,l,mid,x,y)+query(2*o+1,mid+1,r,x,y);  //此处可修改 
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		cin>>p;
		if (p==1) 
		{
			cin>>x>>y>>k;
			add(1,1,n,x,y,k);
		}
		if (p==2)
		{
			cin>>x>>y;
			cout<<query(1,1,n,x,y)<<endl;
		}
	}
	return 0;
}
