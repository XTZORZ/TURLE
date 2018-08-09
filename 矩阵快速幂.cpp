#include <iostream>
using namespace std;
long long n,k,g[200][200],a[200][200],kk[200][200];
const long long mo=1000000007;
void ans()
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) kk[i][j]=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	for (int k=1;k<=n;k++)
	kk[i][j]=(kk[i][j]%mo+(a[i][k]%mo*g[k][j]%mo)%mo)%mo;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) a[i][j]=kk[i][j];
}

void mi()
{
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) kk[i][j]=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	for (int k=1;k<=n;k++)
	kk[i][j]=(kk[i][j]%mo+(g[i][k]%mo*g[k][j]%mo)%mo)%mo;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) g[i][j]=kk[i][j];
}

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) cin>>g[i][j],a[i][i]=1;
	while (k>0)
	{
		if (k&1) ans();//a=a*g%mo;
		k/=2;
		mi();//g=g*g%mo;
	}
	for (int i=1;i<=n;i++)	
	{
		for (int j=1;j<=n;j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
 } 
