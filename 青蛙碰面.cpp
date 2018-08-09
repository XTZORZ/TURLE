#include <iostream>
#define ll long long
using namespace std;
ll n,m,x,y,l,N,X,xx,yy;

ll exgcd(ll a,ll b)
{
	if (!b)
	{
		xx=1; yy=0; return a%l;
	}
	ll ans=exgcd(b,a%b);
	ll kk=xx;
	xx=yy%l; yy=(kk%l-(a/b)*yy%l+l)%l;
	return ans%l;
}
int main()
{
	cin>>x>>y>>m>>n>>l;
	X=x-y; N=n-m; 
	if (N<0) N=-N,X=-X; ll ans=exgcd(N,l);
	if (X%ans) {
		cout<<"Impossible"<<endl;
		return 0;
	}
//	cout<<X<<" "<<N<<" "<<l<<" "<<ans<<endl;
	cout<<(xx*(X/ans)%(l/ans)+(l/ans))%(l/ans)<<endl; //???
	return 0;
}
