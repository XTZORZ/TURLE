
//ɾ����д�� 
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[3000000],b[3000000],x,y,k,cnt;
int w[3000000],l[3000000],r[3000000],rt[3000000];
//wΪ��ǰ���������l�ǵ�ǰ��������ӣ�rΪ�����Ҷ��ӣ�
//��ǰ������ɶ�������ر����������ڵݹ�ķ�Χ�У�
//rt��ǰ���������޹أ�������ʾ[1,i]����֮��ĸ��ڵ㡣

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
	w[ro]=w[pre]+1; l[ro]=l[pre]; r[ro]=r[pre]; //�����������ϻ���ֵ
	if (ll!=rr)  //�߽� 
	{
		int mid=(ll+rr)/2;
//		cout<<mid<<" "<<x<<endl;
		if (x<=mid) l[ro]=add(l[pre],ll,mid,x);  //�޸������� 
		else r[ro]=add(r[pre],mid+1,rr,x); //�޸������� 
	}
	return ro;
}

int query(int ro1,int ro2,int ll,int rr,int k)
{
	int x=w[l[ro2]]-w[l[ro1]];
	if (ll!=rr)
	{
		int mid=(ll+rr)/2;
		if (k<=x) return query(l[ro1],l[ro2],ll,mid,k); //x�����������ڵ�����midֻ�Ƿ�Χ 
		else return query(r[ro1],r[ro2],mid+1,rr,k-x);
	}
	return ll; //һ���ѵ����ڵ㣿�� 
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
	rt[0]=build(1,l);  //�������ܣ��� 
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
		cout<<a[t]<<endl; //t��ӳ�������ֵ���ٴ�ӳ���a����
//		cout<<t<<endl; 
	}
	return 0;
}
