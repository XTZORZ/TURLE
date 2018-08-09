#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node{
	int a;
	int b;
	long long ab; 
}a[10000];
int n,l,ansl,ld,ans[10000],ansd[10000],sum[10000]; 
void time(int x)
{	int t=0;
	for (int i=1;i<=ansl;i++)
	{
		ans[i]=ans[i]*x+t;
		t=ans[i]/10; ans[i]%=10;
		if (t>0&&i>=ansl) ansl++;
	}
}
int div(int x) {
	memset(ansd,0,sizeof(ansd));
	int t=0,ok=1;
	for (int i=ansl;i>0;i--)
	{
		ansd[i]=(ans[i]+10*t)/x;
		t=(ans[i]+10*t)%x;
		if (ansd[i]&&ok) ld=i,ok=0;
	}
    return 0;
}
bool compare() {
	if(l==ld) {
		for(int i=ld;i>=1;i--) {
			if(ansd[i]>sum[i]) return 1;
			if(ansd[i]<sum[i]) return 0;
		}
	}
	if(ld>l) return 1;
	if(ld<l) return 0;
}
void change () {
    memset(sum,0,sizeof(sum));
    for(int i=ld;i>=1;i--) {
        sum[i]=ansd[i];
    } l=ld;
    return ;
}
bool cmp(node a,node b)
{
	return (a.ab<b.ab);
}
int main()
{
	cin>>n;
	for (int i=0;i<=n;i++) 
	{
		cin>>a[i].a>>a[i].b;
		a[i].ab=a[i].a*a[i].b;
	} 
	sort(a+1,a+n+1,cmp);
	ansl=1,ans[1]=1;
    for (int i=1;i<=n;i++)
	{
		time(a[i-1].a); div(a[i].b);
	//	for (int i=ansl;i>=1;i--) cout<<ans[i]; cout<<endl;
	//	for (int i=ld;i>=1;i--) cout<<ansd[i]; cout<<endl;
		if (compare()) change(); 
	}
    for (int i=l;i>=1;i--) cout<<sum[i];
	return 0; 
} 
