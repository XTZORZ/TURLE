#include <iostream>
using namespace std;
long long f[4],n,i;
const int m=1000000007;
int main()
{
	cin>>n;
	f[1]=1; f[2]=1;
	for (int i=3;i<=n;i++) f[i%3]=(f[(i+2)%3]%m+f[(i+1)%3]%m)%m;
	cout<<f[n%3]<<endl;
	return 0;
}
