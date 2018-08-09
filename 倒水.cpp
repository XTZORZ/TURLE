#include <iostream>
#include <iomanip>
using namespace std;
long long e[34],n,n1,k,p,ans=1000000000,m;
double l;
int main()
{
    cin>>n>>k; e[0]=1;
    for (int i=1;i<=32;i++) e[i]=e[i-1]*2;
//	for (int i=1;i<=34;i++)cout<<e[i]<<" ";
    for (int i=1;i<=k-1;i++)
    {
    	m=0;
        while (n>e[m]&&m<=32) m++;
        m--; n-=e[m];
    } m=0;
    while (n>e[m]&&m<=32) m++;
    cout<<e[m]<<" "<<n<<endl;
    ans=e[m]-n;
    cout<<ans<<endl;
    return 0;
}
