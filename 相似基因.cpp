#include <iostream>
using namespace std;
int n,m,dp[1000][1000];
char c;
int a[1000],b[1000];
int g[6][6]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
int k(char c)
{
	if (c=='A') return 0;
	if (c=='C') return 1;
	if (c=='G') return 2;
	if (c=='T') return 3;
}
int main()
{
	cin>>n;
	for (int i=1;i<=1000;i++) a[i]=b[i]=100;
	for (int i=1;i<=n;i++) cin>>c,a[i]=k(c);
	cin>>m;
	for (int i=1;i<=m;i++) cin>>c,b[i]=k(c);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) dp[i][j]=-100000;
	for (int i=1;i<=n;i++) dp[i][0]=dp[i-1][0]+g[a[i]][4];
	for (int i=1;i<=m;i++) dp[0][i]=dp[0][i-1]+g[b[i]][4];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		dp[i][j]=max(dp[i][j],dp[i][j-1]+g[b[j]][4]);
		dp[i][j]=max(dp[i][j],dp[i-1][j]+g[a[i]][4]);
		dp[i][j]=max(dp[i][j],dp[i-1][j-1]+g[a[i]][b[j]]);
	}
	cout<<dp[n][m]<<endl;
	return 0;
}

//dp[i][j]=max(dp[i-1][j],dp[j][i-1])+g[ai][aj
/*5 AGCTA
4 AGCT
7 AGCTATT
9 AGCTTTAAA
*/