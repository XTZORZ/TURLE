#include <iostream>
#include <cmath>
using namespace std;
long long n,ans;
int f[20000000],p[20000000];
bool su[20000000];
long long inline search(long long n)
{
//	cout<<n<<endl;
    	//33554432
        if (f[n])  return f[n]; 
        if (n==1||!su[n]) return 1;	
    }
    int k=1;
//	cout<<n<<endl;
    for (int i=2;i<=n/2;i++)
    {	
//		if (p[i]>n/2) break;
        if (n%i==0) 
        if (n/i<20000000) f[n/i]=search(n/i),k+=f[n/i];
        else k+=search(n/i);
    }
    if (n<=20000000) f[n]=k;
    return k;
}

int main()
{
    cin>>n;
    
    for (int i=2;i<=20000000;i++) {
    if (!su[i]) p[++p[0]]=i;
    for (int j=1;j<=p[0]&&i*p[j]<=20000000;j++)
        {
            su[i*p[j]]=true;
            if (i%p[j]==0) break;
        }
    } //sushu biao
//	for (int i=1;i<=10000;i++) cout<<p[i]<<endl; 
//;5
    ans=search(n);
    cout<<ans<<endl;
    return 0;
}
