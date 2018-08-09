#include <iostream>
#include <cstring>
using namespace std;
int a,b,k,n,s,f[300000],p[300000],ans[300000];
int main()
{
	cin>>k>>n;
	for (int i=1;i<=n;i++) f[i]=1; s=ans[1]=0;
	for (int i=2;i<=n;i++)
	{
		ans[i]=ans[i-1];
		if (f[i]) p[++s]=i,ans[i]++;
		for (int j=1;j<=s;j++)
		{
			if (i*p[j]>n) break;
			f[i*p[j]]=0;
			if (i%p[j]==0) break;
		}
	}
	for(int i=1;i<=k;i++) 
	{
		cin>>a>>b;
		if (a<1||b>n) cout<<"Crossing the line"<<endl;
		else cout<<ans[b]-ans[a-1]<<endl;
	}
	return 0;
}