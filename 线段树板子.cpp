#include <iostream>
#include <cstdio>
using namespace std;
long long c,tr[400000],addc[400000],addj[400000],a[300000];
int n,p;
int q,x,y,m;

void pushup(int o)
{
	tr[o]=(tr[o*2]+tr[o*2+1])%p;
}

void pushdown(int o,int l,int r)
{
	int mid=(l+r)/2;
	tr[o*2]=(tr[o*2]*addc[o]+(mid-l+1)*addj[o])%p; 
	tr[o*2+1]=(tr[o*2+1]*addc[o]+(r-mid)*addj[o])%p;
	
	addc[o*2]=addc[o*2]*addc[o]%p; addc[o*2+1]=addc[o*2+1]*addc[o]%p;	
	addj[o*2]=(addj[o*2]*addc[o]+addj[o])%p;
	addj[o*2+1]=(addj[o*2+1]*addc[o]+addj[o])%p; 
	addc[o]=1; addj[o]=0;  
	return;
}
void build(int o,int l,int r)
{
	addc[o]=1;
	if (l==r) {
		tr[o]=a[l]; return;
	}
	int mid=(l+r)/2;
	build(o*2,l,mid);
	build(o*2+1,mid+1,r);
	pushup(o);
}

void add1(int o,int l,int r,int x,int y,long long c)
{
	if (l>y||r<x) return;
	if (l>=x&&r<=y) {
		tr[o]=tr[o]*c%p; addc[o]=addc[o]*c%p; addj[o]=addj[o]*c%p;
		return; 
	}
	int mid=(l+r)/2;
	pushdown(o,l,r);
	add1(o*2,l,mid,x,y,c);
	add1(o*2+1,mid+1,r,x,y,c);
	pushup(o);
}

void add2(int o,int l,int r,int x,int y,long long c)
{
	
	if (l>y||r<x) return;
	if (l>=x&&r<=y) {
		tr[o]=(tr[o]+(r-l+1)*c)%p; addj[o]+=c;
		return; 
	}
	int mid=(l+r)/2;
	pushdown(o,l,r);
	add2(o*2,l,mid,x,y,c);
	add2(o*2+1,mid+1,r,x,y,c);
	pushup(o);
}

long long query(int o,int l,int r,int x,int y)
{
	if (l>y||r<x) return 0;
	if (l>=x&&r<=y) return tr[o]%p;
	int mid=(l+r)/2;
	pushdown(o,l,r);
	return (query(o*2,l,mid,x,y)%p+query(o*2+1,mid+1,r,x,y)%p)%p;
}

int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n); 
	for (int i=1;i<=m;i++)
	{
//		for (int i=1;i<=2*n+1;i++) cout<<tr[i]<<" ";	cout<<endl;
		scanf("%d",&q);
		switch(q)
		{
			case 1:{
				scanf("%d%d%lld",&x,&y,&c);
				add1(1,1,n,x,y,c);
				break;
			}
			case 2:{
				scanf("%d%d%lld",&x,&y,&c);
				add2(1,1,n,x,y,c);
				break;
			}
			case 3:{
				scanf("%d%d",&x,&y);
				printf("%lld\n",query(1,1,n,x,y)%p); 
				break;
			}
		}
		
	}
	return 0;
}
