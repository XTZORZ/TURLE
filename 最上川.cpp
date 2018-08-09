#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct tr{
    int v;
    int next;
}tr[1000002];
int n,m,a,b,st=0,ans,s,maxx;
int f[500001][21],fir[500001],cha[500001],d[500001];
void add(int a,int b)
{
    tr[++st].v=a; tr[st].next=fir[b]; fir[b]=st;
    tr[++st].v=b; tr[st].next=fir[a]; fir[a]=st;
}
void dfs(int u,int fa)
{
    d[u]=d[fa]+1; f[u][0]=fa;
//    cout<<"!!!!"<<d[u]<<endl;
    for (int i=1;(1<<i)<=d[u];i++)
    f[u][i]=f[f[u][i-1]][i-1];
    for (int i=fir[u];i>0;i=tr[i].next)
    {	
        int v=tr[i].v;
        if (v!=fa) dfs(v,u); 
    }
}

int lca(int a,int b)
{
    if (d[a]>d[b]) swap(a,b);
//    cout<<a<<","<<b<<":1"<<endl;
    for (int i=20;i>=0;i--) 
    if (d[a]<=d[b]-(1<<i)) b=f[b][i];
//     cout<<d[a]<<","<<d[b]<<":2"<<endl;
    if (a==b) return a;
    for (int i=20;i>=0;i--)
    if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
//     cout<<a<<","<<b<<":3"<<endl;
    return f[a][0];
}

void search(int u,int fa)
{
    for (int i=fir[u];i>0;i=tr[i].next)
    if (tr[i].v!=fa){
        search(tr[i].v,u);
        cha[u]+=cha[tr[i].v];
    }
    maxx=max(maxx,cha[u]);
    //cout<<u<<" "<<cha[u]<<endl; 
    return;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) fir[i]=-1;
    for (int i=1;i<=n-1;i++) scanf("%d%d",&a,&b),add(a,b);
    dfs(1,0);//
//	for (int i=1;i<=n;i++) cout<<f[i][1]<<"!";
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        int k=lca(a,b);
        cha[a]++; cha[b]++; cha[k]--; cha[f[k][0]]--; 
    }
    search(1,0);
    printf("%d",maxx);
    return 0;
}
