#include <iostream>
#include <algorithm>
using namespace std;
struct h{
	int v;
	int n;
}x[100001];
int f[200000],t[200000],ha[100000];  //t[i]以i为结尾的最大LIS,树状核心 
//f[i]第i个的最大LIS 
int n,m;
bool cmp(h a,h b)
{
	return a.n<b.n;
}
int find(int a)
{
	int ans=0;
	while (a>0)
	{
		ans=max(ans,t[a]);
		a-=(-a)&a;
	}
	return ans;
}

void push(int a,int ma)
{
	while (a<=100000)
	{
		t[a]=max(t[a],ma);
		a+=(-a)&a;
	}
}
int main()
{
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i].n; x[i].v=i;
	}
	sort(x+1,x+1+n,cmp);
	for (int i=1;i<=n;i++) ha[x[i].v]=i;  //离散
	for (int i=1;i<=n;i++) ha[i]<<endl;
	//for(int i=1;i<=n;i++)
	{
		f[i]=find(ha[i])+1;//当前LIS最大 
		ans=max(ans,f[i]);
		push(ha[i],f[i]);//更新LIS最大 
	}
	cout<<ans<<endl;
	return 0; 
}
