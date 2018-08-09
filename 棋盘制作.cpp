#include <iostream>//求最大矩形：悬线法；
//没了解过现场推怎么推啊QWQ！！  
using namespace std;
int n,m;
int a[2000][2000],h[2000][2000],l[2000][2000],r[2000][2000];
int f[2000][2000];
void che()
{
	cout<<"F:"<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) cout<<f[i][j]<<" ";
		cout<<endl;
	}
	cout<<"L:"<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) cout<<l[i][j]<<" ";
		cout<<endl;
	}
	cout<<"H:"<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) cout<<h[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) f[1][i]=1,r[0][i]=m;
	for (int i=1;i<=n;i++) f[i][1]=1,r[i][m+1]=m,l[i][0]=1;
	
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) {
		cin>>a[i][j];
		if (a[i][j]!=a[i-1][j]||i==1) h[i][j]=h[i-1][j]+1;
		else h[i][j]=1;
	}
	int ans1=0;
	for (int i=2;i<=n;i++)
	for (int j=2;j<=m;j++)
	if (a[i][j]!=a[i-1][j]&&a[i][j]!=a[i][j-1])
	f[i][j]=min(min(f[i][j-1],f[i-1][j]),f[i-1][j-1])+1,ans1=max(ans1,f[i][j]);
	else f[i][j]=1;
	for (int i=1;i<=n;i++)
	{
	for (int j=1;j<=m;j++)
		if (j==1||a[i][j]!=a[i][j-1]) l[i][j]=l[i][j-1];
		else l[i][j]=j;
	for (int j=m;j>=1;j--)
		if (j==m||a[i][j]!=a[i][j+1]) r[i][j]=r[i][j+1];
		else r[i][j]=j;
	}
//	che();
	int ans=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (a[i][j]!=a[i-1][j])
	{
		l[i][j]=max(l[i][j],l[i-1][j]);
		r[i][j]=min(r[i][j],r[i-1][j]);
		ans=max(ans,(r[i][j]-l[i][j]+1)*h[i][j]);
	}
//	che();
	cout<<ans1*ans1<<endl;
	cout<<ans<<endl;
	return 0;
}
/*
6 4
0 1 0 0
1 0 0 1
0 1 0 1
1 0 1 1
0 1 0 1
1 1 1 1
5 5 
0 0 1 1 0
0 1 1 1 0
1 0 1 0 1
1 1 0 1 0
0 0 0 1 1
*/
