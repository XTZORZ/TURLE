#include <iostream>
using namespace std;
int n,a[300000],f[400000],l,r;
int tr[1000000],ans;

void pushup(int o)
{
	tr[o]=max(tr[o*2],tr[o*2+1]);
}

void add(int o,int l,int r,int x,int w)
{
	if (l==r&&l==x) {
		tr[o]=w; return;
	}
	if (r<x||l>x) return;
	int mid=(l+r)/2;
	add(o*2,l,mid,x,w);
	add(o*2+1,mid+1,r,x,w);
	pushup(o);
}

int find(int o,int l,int r,int x,int y)
{
	if (l>y||r<x) return 0;
	if (x<=l&&r<=y) return tr[o];
	int mid=(l+r)/2;
	return max(find(o*2,l,mid,x,y),find(o*2+1,mid+1,r,x,y));
}

int main()
{
	cin>>n>>l>>r;
	for (int i=0;i<=n;i++) cin>>a[i];
	f[l]=a[l];
	add(1,1,n,l,f[l]);
	for (int i=l+1;i<=2*n;i++)
	{
		if (i-l>n) break;
		int k=find(1,1,n,(i>r)?i-r:1,i-l);
		f[i]=k+a[i];
		add(1,1,n,i,f[i]);
	}
//	for (int i=1;i<=2*n;i++) cout<<f[i]<<" ";
	int i=n+1;
	while (f[i]) ans=max(ans,f[i]),i++;
	cout<<ans<<endl;
	return 0;
}
