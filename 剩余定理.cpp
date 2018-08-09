// luogu-judger-enable-o2
#include <iostream>
#include <cstring>
#include <cstdio>
#define ll __int128
using namespace std;
ll n,x,y,a[2000000],m[2000000];
ll read()
{
    ll x=0; char c=getchar();
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)) x=x*10+(c-'0'),c=getchar();
    return x;
}
void write(ll x)
{
    if (x>9) write(x/10);
    putchar(x%10+'0');
}
ll gcd(ll a,ll b)
{
    if (!b) 
    {
        x=1,y=0; return a;
    }
    else{
        ll ans=gcd(b,a%b);
        ll k=x;
        x=y; y=k-(a/b)*y; return ans;
    }
    
}
int main()
{
    n=read();
    m[1]=read(); a[1]=read(); 
    for (int i=2;i<=n;i++)
    {
        m[i]=read();a[i]=read();
        ll l=gcd(m[i-1],m[i]),gb=m[i-1]*m[i]/l;
        ll aa=a[i]-a[i-1];
//		cout<<l<<" "<<gb<<" "<<x<<" "<<aa<<endl;
//		if (aa%l) break; 
//		ll q=gcd(m[i-1]/gb,m[i]/gb);
        ll kk=(x*aa/l)%(m[i]/l);
        kk=(kk)%(m[i]/l);
//		cout<<kk<<endl;;
        a[i]=(a[i-1]%gb+kk*m[i-1]%gb)%gb; 
        m[i]=gb;
        a[i]=(a[i]%gb+gb)%gb;
//		cout<<a[i]<<" "<<m[i]<<endl;
//		cout<<"~~~"<<endl;
//		if (i==n) return 0;
    }
    write(a[n]);
//	cout<<"NONO"<<endl;
}
