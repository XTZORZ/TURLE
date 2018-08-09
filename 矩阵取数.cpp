#include <bits/stdc++.h>
using namespace std;
__int128 ans,f[200][200],e[200];
int n,m,a[200];
void p(__int128 x)
{
    if(x==0) return;
    else if(x) p(x/10);
    putchar(x%10+'0');
}
__int128 dfs(int l,int r,int k)
{
	if (l==r) return f[l][r]=a[l]*e[k];
	if (f[l][r]) return f[l][r];
f[l][r]=max(dfs(l+1,r,k+1)+a[l]*e[k],dfs(l,r-1,k+1)+a[r]*e[k]);

   return f[l][r];
}
int main()
{
	cin>>n>>m; e[0]=1;
	for (int i=1;i<=100;i++) e[i]=e[i-1]*2;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) cin>>a[j];
		memset(f,0,sizeof(f));
		ans+=dfs(1,m,1);
	}
	if (ans==0) cout<<0;
	else p(ans);
	return 0;
}