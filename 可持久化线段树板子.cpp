
//删了重写。 
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[3000000],b[3000000],x,y,k,cnt;
int w[3000000],l[3000000],r[3000000],rt[3000000];
//w为当前区间个数，l是当前区间左儿子，r为区间右儿子；
//当前区间是啥？是隐藏变量，暗含在递归的范围中；
//rt与前几个变量无关，单纯表示[1,i]区间之间的根节点。

void check()
{
	for (int i=0;i<=cnt;i++)
	cout<<rt[i]<<" "<<l[i]<<" "<<r[i]<<" "<<w[i]<<endl;
	cout<<"~~~~~~~~~"<<endl;
	return; 
}

 
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
	w[ro]=w[pre]+1; l[ro]=l[pre]; r[ro]=r[pre]; //接上树，附上基础值
	if (ll!=rr)  //边界 
	{
		int mid=(ll+rr)/2;
//		cout<<mid<<" "<<x<<endl;
		if (x<=mid) l[ro]=add(l[pre],ll,mid,x);  //修改左子树 
		else r[ro]=add(r[pre],mid+1,rr,x); //修改右子树 
	}
	return ro;
}

int query(int ro1,int ro2,int ll,int rr,int k)
{
	int x=w[l[ro2]]-w[l[ro1]];
	if (ll!=rr)
	{
		int mid=(ll+rr)/2;
		if (k<=x) return query(l[ro1],l[ro2],ll,mid,k); //x是左儿子区间节点数，mid只是范围 
		else return query(r[ro1],r[ro2],mid+1,rr,k-x);
	}
	return ll; //一定搜到根节点？？ 
}

int main()
{
	cin>>n>>m;
	
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i]; b[i]=a[i];
	}
	sort(a+1,a+n+1); 
	int l=unique(a+1,a+n+1)-(a+1);
	rt[0]=build(1,l);  //空树不管？？ 
	for (int i=1;i<=n;i++)
	{
		
		int t=lower_bound(a+1,a+l+1,b[i])-a;
		rt[i]=add(rt[i-1],1,l,t);
//		check();
//		cout<<t<<endl;
	}
	for (int i=1;i<=m;i++) 
	{
		cin>>x>>y>>k;
		int t=query(rt[x-1],rt[y],1,l,k);
		cout<<a[t]<<endl; //t是映射出来的值，再次映射回a数组
//		cout<<t<<endl; 
	}
	return 0;
}
