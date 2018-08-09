#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>
//第二个条件多余，因为最近，所以AB<=BC,BC<=CA,AC<=BA，三者应相等。
//否决最短的其实都一样_(:з」∠)_ 
using namespace std;
double ans=0,d[10000];
int p[10000][3],n,min;
bool v[10000];

double dis(int x,int y) 
{
	return sqrt((double)(p[x][1]-p[y][1])*(p[x][1]-p[y][1])+
	(double)(p[x][2]-p[y][2])*(p[x][2]-p[y][2]));
	//强制转换？！！！！！！！ 
}

void prim(int b)
{
	for (int i=1;i<=n;i++)
	{
		double min=100000000;
		int minj=0;
		for (int j=1;j<=n;j++) if (!v[j]&&d[j]<min) min=d[j],minj=j;
		v[minj]=1; ans+=d[minj];
		for (int j=1;j<=n;j++) 
		if (!v[j]&&dis(minj,j)<d[j]) d[j]=dis(minj,j);
	}
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i][1]>>p[i][2];
	for (int i=1;i<=n;i++) d[i]=200000000; d[1]=0;
	prim(1);
	cout<<fixed<<setprecision(2)<<ans<<endl;
	return 0;
} 
