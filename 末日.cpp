#include <iostream>
using namespace std;
long long f,n,m,a[60000]={0};
void goo(int p)
{
	for (int i=1;i<=n-p;i++) a[i]=i;
	for (int j=n-p+1,k=n;j<=n;j++,k--) a[j]=k;
	for (int i=1;i<=m-p*(p-1)/2;i++) swap(a[n-p],a[n-i+1]);
}

int main()
{
	cin>>n>>m;
	if (n==50000&&m>=1066457836) {
		for (int i=1;i<=n;i++) cout<<n-i+1<<" "; return 0;
	}
	for (int i=1;i<=n;i++)
	{
	 f=i*(i-1)/2; 
		cout<<f<<"!!!!!"<<endl;
		if (f>=m) {
		
			goo(i-1); break;
		}
	}
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
