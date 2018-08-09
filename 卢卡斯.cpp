
/*#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
ll n,m,p,zz,f[2000000];
ll ni(ll a,ll p,ll mo)  //别忘膜P 
{
	ll ans=1,pp=p;
	a=a%mo;  //pow初始a 
	while (pp)
	{
		if (pp%2) ans=ans%mo*a%mo;
		a=a*a%mo; pp/=2;
	}
//	cout<<a<<"^"<<p<<endl;
	return ans%mo;
}
int main()
{
	cin>>zz;
for (int qq=1;qq<=zz;qq++)
{
	cin>>n>>m>>p;
	memset(f,0,sizeof(f));
	f[1]=1; for (int i=2;i<=n+m;i++) if (i!=p) f[i]=(f[i-1]%p*i%p)%p;
	else f[i]=f[i-1]*i;
	for (int i=1;i<=n+m;i++) cout<<f[i]<<" ";
	cout<<f[n+m]<<" "<<f[m]<<" "<<f[n]<<endl;
	cout<<ni(f[m],p-2,p)<<" "<<ni(f[n],p-2,p)<<endl;
	cout<<(f[n+m]%p*ni(f[m],p-2,p)%p*ni(f[n],p-2,p)%p)%p<<endl;
}
	return 0;
} */

//以上失败，因为超过求阶乘超过p必会变0
 #include <iostream>
#include <cstring>
using namespace std;
#define ll long long
ll n,m,p,zz,f[2000000];
ll ni(ll a,ll p,ll mo) //别忘膜P 
{
	ll ans=1,pp=p;
	a=a%mo;  //pow初始a 
	while (pp)
	{
		if (pp%2) ans=ans%mo*a%mo;
		a=a*a%mo; pp/=2;
	}
//	cout<<a<<"^"<<p<<endl;
	return ans%mo;
}

ll c(ll m,ll n,ll p)
{
	if (m>n) return 0;
	return (f[n]*ni(f[m],p-2,p)%p*ni(f[n-m],p-2,p)%p+p)%p;
} 

ll lucas(ll m,ll n)
{
//	cout<<c(m%p,n%p,p)<<endl;cout<<m<<","<<n<<endl;
	if (!m) return 1;
	else return (c(m%p,n%p,p)*lucas(m/p,n/p)%p);
}
int main()
{
	cin>>zz;
for (int qq=1;qq<=zz;qq++)
{
	cin>>n>>m>>p;
	memset(f,0,sizeof(f)); f[0]=1;
	f[1]=1; for (int i=2;i<=p;i++) f[i]=(f[i-1]%p*i%p)%p;
//	cout<<f[n+m]<<" "<<f[m]<<" "<<f[n]<<endl;
//	cout<<ni(f[m],p-2,p)<<" "<<ni(f[n],p-2,p)<<endl;
	cout<<lucas(m,n+m)<<endl;
}
	return 0;
}
//C(n,m)=(m)!/(n!*(m-n)!);
