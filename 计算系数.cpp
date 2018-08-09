#include <iostream>
#define ll long long
using namespace std;
const ll p=10007;
ll a,b,k,n,m;
ll j[10000],jn[10000],inv[10000];

ll c(ll m,ll n){
	return (j[m]%p*jn[n]%p*jn[m-n]%p)%p;
}

ll ksm(ll x,ll k)
{
	ll ans=1;
	while (k)
	{
		if (k%2) ans=ans%p*x%p;
		x=x%p*x%p; k/=2;
	}
	return ans;
}

int main()
{
    cin>>a>>b>>k>>n>>m; j[1]=1;
    for (int i=2;i<=k;i++) j[i]=j[i-1]*i%p;
    inv[1]=1;
    for (int i=2;i<=k;i++) inv[i]=((-(p/i)*inv[p%i])%p+p)%p;
    jn[1]=1;
    for (int i=2;i<=k;i++) jn[i]=jn[i-1]*inv[i]%p;
//    for (int i=1;i<=k;i++) cout<<j[i]<<" "<<jn[i]<<" "<<inv[i]*i%p<<endl;
    cout<<c(k,m)%p*ksm(a,n)*ksm(b,m)%p<<endl;
    return 0;
}
