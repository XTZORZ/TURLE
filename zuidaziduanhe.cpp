#include <iostream>
using namespace std;
int n,a[200100]={0},f[200100]={0},ans,k=-100000000;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		k=max(k,a[i]);
	}
	if (k<=-1) {
	cout<<k<<endl;	return 0;
	}
	f[1]=a[1];
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
		if (f[i]<a[i]) f[i]=a[i];
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
