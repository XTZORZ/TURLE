#include <iostream>
using namespace std;
int n,num,su[100000],fai[100000],ans; //su[i]: (NO.i) prime
bool pd[100000];
int main()
{
	cin>>n; fai[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!pd[i]) pd[i]=1,su[++num]=i,fai[i]=i-1;
		for (int j=1;j<=num&&su[j]*i<=n;j++)
		{
			pd[i*su[j]]=1; if (i%su[j]==0) {
				fai[i*su[j]]=fai[i]*su[j]; break;	
			}
			else fai[i*su[j]]=fai[i]*(su[j]-1);
		}
	}
	ans=3;
	for (int i=2;i<=n-1;i++) ans+=2*fai[i];
	if (n==1) cout<<"1"<<endl;
	else cout<<ans<<endl;
	return 0;
}
