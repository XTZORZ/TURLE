#include<algorithm>
#include <cstdio>
#include <climits> 
#include <iostream>
using namespace std;
int n,m,v,e,a,b,w;
int g[400][310];
int c[4000],d[4000];
double dp[2100][2011][2],k[4000],ans=400000.0;  //i教室，j修改，当前换不换 
double minn(double a,double b)
{
return (a>b)?b:a;
}
int main()
{	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	for (int i=1;i<=n;i++) scanf("%lf",&k[i]);
	//for (int i=1;i<=n;i++) cout<<c[i]<<" "<<d[i]<<" "<<k[i]<<endl;
	for (int i=1;i<=v;i++)
	for (int j=1;j<=v;j++)
	if (i==j) g[i][j]=0;
	else g[i][j]=INT_MAX/2;
	for (int i=1;i<=e;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		g[b][a]=g[a][b]=min(g[a][b],w); 
	}
	
	for (int q=1;q<=v;q++)
	for (int i=1;i<=v;i++)
	for (int j=1;j<=v;j++) g[i][j]=min(g[i][j],g[i][q]+g[q][j]);
	for (int i=1;i<=n;i++)
	for(int j=0;j<=m;j++) dp[i][j][0]=dp[i][j][1]=0x3f3f3f3f;
	dp[1][0][0]=0.0; dp[1][1][1]=0.0;

	for (int i=2;i<=n;i++)
	for (int j=0;j<=i&&j<=m;j++)
	{
		
		dp[i][j][0]=minn(dp[i-1][j][0]+1.0*g[c[i-1]][c[i]],dp[i-1][j][1]+1.0*g[c[i-1]][c[i]]*(1.0-k[i-1])+1.0*g[d[i-1]][c[i]]*k[i-1]);
		if (j>=1) {
			
	dp[i][j][1]=minn(dp[i-1][j-1][0]+1.0*g[c[i-1]][d[i]]*k[i]+1.0*g[c[i-1]][c[i]]*(1.0-k[i]),
		dp[i-1][j-1][1]+1.0*g[d[i-1]][d[i]]*k[i-1]*k[i]+1.0*g[c[i-1]][c[i]]*(1.0-k[i-1])*(1.0-k[i])+		
		1.0*g[c[i-1]][d[i]]*(1.0-k[i-1])*k[i]+1.0*g[d[i-1]][c[i]]*(1.0-k[i])*k[i-1]); 
	//	printf("%.2lf,%.2lf ",dp[i][j][0],dp[i][j][1]);
	//	printf("\n");	
	}
	}

	for (int j=0;j<=m;j++) ans=min(ans,dp[n][j][0]),ans=min(ans,dp[n][j][1]);
	printf("%.2lf",ans);
	return 0;
}
