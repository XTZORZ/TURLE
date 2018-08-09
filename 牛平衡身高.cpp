#include <iostream> 
#include <climits>
using namespace std;
int tr1[200000],tr2[200000]; //1--max,2--min
int n,q,a,b,h[60000];
void build(int o,int l,int r)
{
	if (l==r) {
		tr1[o]=h[l],tr2[o]=h[r]; return;
	}
	int mid=(l+r)/2;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
	tr1[o]=max(tr1[o*2],tr1[o*2+1]);
	tr2[o]=min(tr2[o*2],tr2[o*2+1]);
}

int query(int o,int l,int r,int x,int y)
{
	if (l>y||r<x) return 0;
	if (l>=x&&r<=y) return tr1[o];
	int mid=(l+r)/2;
	return max(query(o*2,l,mid,x,y),query(o*2+1,mid+1,r,x,y));
}
int query1(int o,int l,int r,int x,int y)
{
	if (l>y||r<x) return INT_MAX;
	if (l>=x&&r<=y) return tr2[o];
	int mid=(l+r)/2;
	return min(query1(o*2,l,mid,x,y),query1(o*2+1,mid+1,r,x,y));
}
int main()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>h[i];
	build(1,1,n);
//for (int i=1;i<=3*n;i++) cout<<tr1[i]<<" "<<tr2[i]<<endl;
	for (int i=1;i<=q;i++)
	{
		cin>>a>>b;
		cout<<query(1,1,n,a,b)-query1(1,1,n,a,b)<<endl; 
	}
	return 0;
} 
