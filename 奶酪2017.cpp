#include <iostream>
#include <cmath>
using namespace std;
long long x[10001],y[10001],z[10001]={0},h[10001],t,n,m,r,high;
bool dist[1001],ans;
bool v[2001]={0},g[2002][2002]={0};
long long sqr(long long a)
{
	return a*a;
}
bool spfa(int b)
{
	int t=1,w=0;
	for (int i=1;i<=n+1;i++) {dist[i]=false; v[i]=false; h[i]=0;}
	dist[b]=true;
	h[1]=b; v[b]=true;
	while (w!=t)
	{
		w=(w%(n+1))+1;
		int k=h[w]; v[k]=false;
		for (int i=1;i<=n+1;i++) if (dist[k]&&g[k][i]) 
		{
			dist[i]=true;
			if (!v[i]) { t=(t%(n+1))+1; h[t]=i; v[i]=true;}
		}
	}
	if (dist[n+1]) return true;
	else return false;
}
void qsort(int l,int r)
{
	int i,j,mid,t;
	i=l;j=r;
	mid=z[(l+r)/2];
	while (i<=j)
	{
		while (z[i]<mid) i++;
		while (z[j]>mid) j--;
		if (i<=j) 
		{
			t=x[i];x[i]=x[j];x[j]=t;
			t=y[i];y[i]=y[j];y[j]=t;
			t=z[i];z[i]=z[j];z[j]=t;
			i++;j--;
		}
	}
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}
int main()
{
cin>>t;
for (int qqq=1;qqq<=t;qqq++)
{
	ans=false;
	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=n+1;j++) g[i][j]=0;
	cin>>n>>high>>r; int i=0;
	for (i=1;i<=n;i++) cin>>x[i]>>y[i]>>z[i];
	qsort(1,n);
	for (i=1;i<=n;i++)
	{	for (int j=1;j<i;j++) if (sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]))<=2*r) {g[j][i]=true; }
		if (z[i]-r<=0) g[0][i]=true; 
		if (z[i]+r>=high) g[i][n+1]=true;
	}
	for (int i=1;i<=n;i++)
	if (g[0][i]) 
	{
		if (spfa(i)) {ans=true; break;}
	}
	if (ans) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

}
	return 0;
}
