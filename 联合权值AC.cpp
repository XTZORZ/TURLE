#include <iostream>
using namespace std;
struct tree{
	int v;
	int next;
}t[500000];
int n,x,y,dep,fir[400000],st;
//int f[10000][30],d[10000];
long long max1,max2,t1,t2,ans1,ans2,w[600000];

void add(int u,int v)
{
	t[++st].v=u; t[st].next=fir[v]; fir[v]=st;
	t[++st].v=v; t[st].next=fir[u]; fir[u]=st;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n-1;i++)
	cin>>x>>y,add(x,y);
	for (int i=1;i<=n;i++)cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		max1=max2=0;
		t1=t2=0;
		for (int j=fir[i];j>0;j=t[j].next)
		{
			int v=t[j].v;
			if (w[v]>max1) max2=max1,max1=w[v];
			else if (w[v]>max2) max2=w[v];
			t1=t1%10007+w[v]%10007;
			t2=t2%10007+w[v]*w[v]%10007;
		}
		t1%=10007; t1=t1*t1%10007;
		ans1=(ans1+t1-t2+10007)%10007;
		ans2=max(ans2,max1*max2);
	}
	cout<<ans2<<" "<<ans1%10007<<endl; 
	return 0;
}
