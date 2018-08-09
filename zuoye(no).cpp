#include <iostream>
using namespace std;
int n,m,a[401],num[30][30],t[30][30],k[30],last[30]={0};
bool used[30][8000];
bool check(int b,int l,int mac)
{
    for(int i=b;i<b+l;i++) if(used[mac][i]) return false;
    return true;
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>num[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>t[i][j];
    for(int i=1;i<=n*m;i++)
    {
        k[a[i]]++;
        int x=a[i],y=k[a[i]],z=num[x][y];
        int j=last[x];
		while(true)
        {	
            if(check(j,t[x][y],z))
            {
                for(int k=j;k<j+t[x][y];k++) used[z][k]=true;
                last[x]=j+t[x][y];
                break;
            }
			j++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,last[i]);
    }
    cout<<ans<<endl;
    return 0;
}
