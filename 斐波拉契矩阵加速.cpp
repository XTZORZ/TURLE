#include <iostream>
#include <cstring>
using namespace std;
long long n;
const long long mo=1000000007;
long long g[2][4],a[4][4],kk[4][4],p[4][4];

void ans()
{
	memset(kk,0,sizeof(kk));
	for (int i=1;i<=2;i++)
	for (int j=1;j<=2;j++)
	for (int k=1;k<=2;k++)
	{
		kk[i][j]=(kk[i][j]%mo+(p[i][k]*a[k][j])%mo)%mo;
	}
	for (int i=1;i<=2;i++)
	for (int j=1;j<=2;j++) p[i][j]=kk[i][j];
}

void mi()
{
	memset(kk,0,sizeof(kk));
	for (int i=1;i<=2;i++)
	for (int j=1;j<=2;j++)
	for (int k=1;k<=2;k++)
	{
		kk[i][j]=(kk[i][j]%mo+(a[i][k]*a[k][j])%mo)%mo;
	}
	for (int i=1;i<=2;i++)
	for (int j=1;j<=2;j++) a[i][j]=kk[i][j];
}

int main()
{
	cin>>n;
	a[1][1]=0,a[1][2]=a[2][1]=a[2][2]=1;
	for (int i=1;i<=2;i++) p[i][i]=1;
	g[1][1]=g[1][2]=1; 
	n--;
	while (n>0)
	{
		if (n&1) ans();
		n/=2;
		mi();
	}
	memset(kk,0,sizeof(kk));
	for (int i=1;i<=2;i++)
	for (int k=1;k<=2;k++)
	{
		kk[1][i]=(kk[1][i]%mo+(g[1][k]*p[i][k])%mo)%mo;
	}
	cout<<kk[1][1]%mo<<endl;
	return 0;
}
