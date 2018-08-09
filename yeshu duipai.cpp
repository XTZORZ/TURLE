#include <iostream>
using namespace std;
long long n,nn,ans;
int main()
{
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		nn=i; 
		while (nn!=0)
		{
			ans+=nn%10;
			nn/=10;
		}
	}
	cout<<ans<<endl;
	return 0;
}
