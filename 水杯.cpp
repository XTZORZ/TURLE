#include <iostream>
#include <iomanip>
using namespace std;
long long e[34],n,n1,k,p,ans=1000000000,m;
double l;
int main()
{
	cin>>n>>k; e[0]=1;
	for (int i=1;i<=32;i++) e[i]=e[i-1]*2;
//	for (int i=1;i<=34;i++)cout<<e[i]<<" ";
	for (int i=1;i<=k;i++)
	{
		p=2*p+1; m=0;
		l=n*1.00/p;  while (l>1.0*e[m]) m++;
		n1=e[m]*p;
	//	cout<<n<<" "<<fixed<<setprecision(2)<<l<<endl;
		if (n1-n>=0)ans=min(ans,n1-n);
	}
	cout<<ans<<endl;
	return 0;
}