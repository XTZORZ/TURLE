#include <fstream>
#include <cstdio>
using namespace std;
const int mm=19260817;
long long d[300000],tr[900000],tr1[900000],b[300000]; //tr到5的区间和, tr1 
int n,m,ans,x,l,r;
//ifstream cin("1.txt");
//ofstream cout("2.txt");

long long moo(int n,int x)
{
	return (d[n]%mm-d[x]%mm+mm)%mm;
}
void pushup(int o)
{
    tr[o]=(tr[o<<1]%mm+tr[o<<1|1]%mm)%mm;
}

void pushup1(int o)
{
    tr1[o]=(tr1[o<<1]%mm+tr1[o<<1|1]%mm)%mm;
}

void build(int o,int l,int r)
{
    if (l==r)
    {
        tr[o]=b[l]*moo(n,l)%mm;
        return;
    }
    int mid=(l+r)/2;
    build(o<<1,l,mid); build(o<<1|1,mid+1,r); 
    pushup(o);
}

void build1(int o,int l,int r)
{
    if (l==r)
    {
        tr1[o]=b[l]%mm;
        return;
    }
    int mid=(l+r)>>1;
    build1(o<<1,l,mid); build1(o<<1|1,mid+1,r); 
    pushup1(o);
}

int query(int o,int l,int r,int x,int y)
{
    if (r<x||l>y) return 0;
    if (l>=x&&r<=y) return tr[o];
    int mid=(l+r)>>1;
    return query(o<<1,l,mid,x,y)%mm+query(o<<1|1,mid+1,r,x,y)%mm;
}

int query1(int o,int l,int r,int x,int y)
{
    if (r<x||l>y) return 0;
    if (l>=x&&r<=y) return tr1[o];
    int mid=(l+r)>>1;
    return query1(o<<1,l,mid,x,y)%mm+query1(o<<1|1,mid+1,r,x,y)%mm;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n-1;i++)
    {
        scanf("%lld",&d[i+1]);
        d[i+1]=(d[i+1]%mm+d[i]%mm)%mm;
        
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]); b[i]%=mm;
    }
    build(1,1,n); build1(1,1,n);
//	for (int i=1;i<=2*n+1;i++) cout<<tr[i]<<" "<<tr1[i]<<endl;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&l,&r); ans=0;
//		cout<<" "<<query(1,1,n,l,r)<<" "<<query1(1,1,n,l,r)<<endl;
        if (l>=x) ans=(query1(1,1,n,l,r)*moo(n,x)%mm-query(1,1,n,l,r)%mm+mm)%mm;
        else if (r<=x) ans=(query(1,1,n,l,r)%mm-query1(1,1,n,l,r)*moo(n,x)%mm+mm)%mm;
        else ans=(query(1,1,n,l,x)%mm-query1(1,1,n,l,x)*moo(n,x)%mm+mm)%mm+
                 (query1(1,1,n,x+1,r)*moo(n,x)%mm-query(1,1,n,x+1,r)%mm+mm)%mm;
        printf("%lld\n",ans%mm);
    }
    return 0;
}
