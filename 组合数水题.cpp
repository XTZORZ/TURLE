#include <iostream>
#define ll long long
using namespace std;
const ll p=6662333;
ll n;
ll ksm(ll x,ll k)
{
	ll ans=1;
	while (k)
	{
		if (k%2) ans=ans*x%p;
		x=x*x%p; k/=2;
	}
	return ans%p;
}
int main()
{
	cin>>n;
	cout<<ksm(2,(n-1))<<endl;
	return 0;
}
