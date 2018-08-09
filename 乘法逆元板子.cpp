#include <iostream>
#include <cstdio>
using namespace std;
long long n,p,d[4000000];
int main()
{
	cin>>n>>p;
	d[1]=1; cout<<1<<endl;
	for (int i=2;i<=n;i++)
	d[i]=((-(p/i)*d[p%i])%p+p)%p,printf("%lld\n",(d[i]+p)%p);
	return 0; 
}
