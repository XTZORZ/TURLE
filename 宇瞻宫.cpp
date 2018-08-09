#include <iostream>//求最大矩形：悬线法；
//没了解过现场推怎么推啊QWQ！！ 
using namespace std;
int n,m,a[2000][2000],h[2000][2000],l[2000][2000],r[2000][2000];
char c;

void che()
{
	cout<<"R:"<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) cout<<r[i][j]<<" ";
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
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		cin>>c;
		if (c=='R') a[i][j]=0;
		else a[i][j]=1;
		if (a[i][j]) h[i][j]=h[i-1][j]+1;
	}
	for (int i=1;i<=m;i++) r[0][i]=m+1;
	for (int i=1;i<=n;i++) r[i][m]=(a[i][m])?m+1:m;
	for (int i=1;i<=n;i++)
	{
	for (int j=m-1;j>=1;j--)  //since it can count all the points
		if (a[i][j]) r[i][j]=r[i][j+1];
		else r[i][j]=j;	
	for (int j=1;j<=m;j++)
		if (a[i][j]) l[i][j]=l[i][j-1];
		else l[i][j]=j;
	}
//	che();
	int ans=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
{
	if (a[i-1][j]&&a[i][j])
	{
		l[i][j]=max(l[i][j],l[i-1][j]);
		r[i][j]=min(r[i][j],r[i-1][j]);
		
	}ans=max(ans,(r[i][j]-l[i][j]-1)*h[i][j]);
}
//	che();
	cout<<3*ans<<endl;
	return 0;
}
