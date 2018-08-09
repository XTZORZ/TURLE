#include<iostream>
#define ll long long
using namespace std;
ll n,m,l,x,y;

ll exgcd(ll a,ll b)
{
    if (!b) 
    {
        x=1,y=0; return a;
    }
    else{
        ll ans=exgcd(b,a%b);
        ll k=x;
        x=y; y=k-(a/b)*y; return ans;
    }
}

ll ksm(ll x,ll k)
{
	ll ans=1; ll now=x;
	while (k!=0)
	{
		if (k%2) ans=(ans*x)%n;
		now=now*x%n; k/=2;
	}
	return ans%n;
}

int main()
{
	cin>>n>>m>>l; n++;
	ll m2=ksm(2,m); 
	ll qwq=exgcd(m2,n); while (x<0) x+=n;
	l=l*x%n;
	cout<<l<<endl;
	return 0;
}
