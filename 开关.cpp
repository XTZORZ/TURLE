#include<iostream>
using namespace std;
int n,m,p,x,y;
int tr[500000];
bool addv[500000];
void pushup(int o)
{
	tr[o]=tr[o*2+1]+tr[o*2];
}

void pushdown(int o,int l,int r)
{
	addv[o*2]=!addv[o*2]; addv[o*2+1]=!addv[o*2+1];
	int mid=(l+r)/2;
	tr[o*2]=(mid-l+1)-tr[o*2];
	tr[o*2+1]=(r-mid)-tr[o*2+1];
	addv[o]=0;
}

void change(int o,int l,int r,int x,int y)
{
	if (x>r||l>y) return;
	if (x<=l&&r<=y) {
		tr[o]=(r-l+1)-tr[o]; addv[o]=!addv[o];
		cout<<l<<" "<<r<<" "<<tr[o]<<endl;
		return;
	}
	if (addv[o]) pushdown(o,l,r);
	int mid=(l+r)/2;
	change(o*2,l,mid,x,y);
	change(o*2+1,mid+1,r,x,y);
	pushup(o);
	return;
}

int query(int o,int l,int r,int x,int y)
{
	if (x>r||l>y) return 0;
	if (x<=l&&r<=y) return tr[o];
	if (addv[o]) pushdown(o,l,r);
	int mid=(l+r)/2;
	return query(o*2,l,mid,x,y)+query(o*2+1,mid+1,r,x,y);
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>p>>x>>y;
		if (p==0) change(1,1,n,x,y);
		if (p==1) cout<<query(1,1,n,x,y)<<endl; 
		for (int i=1;i<=2*n+1;i++) cout<<tr[i]<<endl;
		cout<<endl;
	}
	return 0;
}
