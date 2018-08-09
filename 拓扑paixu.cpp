#include <iostream>
using namespace std;
struct e{
	int v;
	int next;
}e[100000];
int t[100000],f[100000]={0},q[100000]={0},in[100000]={0},of[100000],ans[100000],n,ma,pq,p,en;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>pq>>t[i]>>p;
		while (p!=0)
		{
			e[++en].v=i;
			e[en].next=f[p];
			f[p]=en;
			in[i]++; of[p]++;
			cin>>p;
		}
	}
	int h=0,tt=0;
	for (int i=1;i<=n;i++) if (!in[i]) tt++,q[tt]=i,ans[i]=t[i];
	while (h!=tt)
	{
		h=(h+1)%n;  int k=q[h];
		for (int i=f[k];i>0;i=e[i].next)
		{
			int v=e[i].v;
			in[v]--; ans[v]=max(ans[v],ans[k]+t[v]);
//			cout<<"ans"<<ans[v]<<endl;
			if (in[v]==0) tt=(tt+1)%n,q[tt]=v;
			ma=max(ma,ans[v]);
		}
	}
//	for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
	cout<<ma<<endl;
	return 0;
}
