#include <iostream>
using namespace std;
int n,m,p[1000000];
bool b[10000000];
int main()
{
	cin>>n>>m;
	b[1]=true;
	for (int i=2;i<=n;i++)
	{
		if (!f[i]) p[++p[0]]=i;
		for (int i=1;i<=p[0]&&i*p[j]<=n;i++) 
		{
			b[i*p[j]]=true;
			if (i%p[j]==0) break;
		}
	}
	for (int i=1;i<=p[0];i++) cout<<p[i]<<" ";
	return 0;
}
