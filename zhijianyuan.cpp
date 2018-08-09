#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,s;
ll w[200000]={0},v[200000]={0},l[200000]={0},r[200000]={0};
ll go(ll l,ll r,ll k)
{
	ll j=0,ans=0;
	for (ll i=l;i<=r;i++)
	{
		if (w[i]>=k) {j++; ans+=v[i];}
	}
//	cout<<j<<" "<<ans<<endl;
	return j*ans;
}
ll abs(ll a)
{
	return (a<0)?(-a):a;
}
int main()
{
	ll l1=0,r1=0,i=0,y=0,ans=100000000;
	cin>>n>>m>>s;
	for (i=1;i<=n;i++) {
		cin>>w[i]>>v[i];
		r1=((w[i]>r1)?w[i]:r1);
	}
	r1++;
	for (i=1;i<=m;i++) cin>>l[i]>>r[i];
	while (l1<r1)
	{
		int w=(l1+r1)/2;
		y=0;
//		cout<<"w"<<w<<endl;
		for (i=1;i<=m;i++)
		{
			y+=go(l[i],r[i],w);
		}
		ans=min(ans,abs(y-s));
		if (y-s<0) r1=w;
		else if (y-s>0) l1=w+1;
//		cout<<y<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
/*
10 10 1475400
23954 25180
18805 2701
17195 5663
7044 13659
8139 30927
19774 25516
7472 4572
5999 6166
1185 13621
10414 26521
2 10
4 7
5 8
1 6
2 7
1 3
2 7
3 4
1 6
1 10
*/
