#include <iostream>
using namespace std;
int l,r,n,c,ax=1000000,d[100],a[100],w[100],dp[100][100];
int l1,r1;
bool v[100];
void search(int now,int la,int ans,int t,int l,int r)
{
//	cout<<" "<<l<<" "<<r<<" "<<ans<<endl;
	if (t==n+1){ ax=min(ax,ans);
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//	cout<<endl; 
	return;}
	else
{
	if (now==0||now==n+1) return;
	int k=0; a[t]=now;
	
	if (now>la)
		k=(d[now]-d[la])*(w[n]-w[r1]+w[l1-1]);
	else k=(d[la]-d[now])*(w[n]-w[r1]+w[l1-1]);
//	cout<<k<<" "<<d[la]-d[now]<<endl;
l1=l,r1=r;
		search(l-1,now,ans+k,t+1,l-1,r);
l1=l,r1=r;
		search(r+1,now,ans+k,t+1,l,r+1);
}
}
int main()
{
	cin>>n>>c;
	for (int i=1;i<=n;i++)
	{
		cin>>d[i]>>w[i];
		w[i]+=w[i-1];
	}
	search(c,c,0,1,c,c);
	cout<<ax<<endl;
	return 0;
}