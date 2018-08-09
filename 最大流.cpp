#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct tr{
    int v;
    int next;
}tr[100002];
int n,m,a,b,st=0,ans,maxx;
int f[50000][20],fir[50001],cha[50001],d[50001];
void add(int a,int b)
{
    tr[++st].v=a; tr[st].next=fir[b]; fir[b]=st;
    tr[++st].v=b; tr[st].next=fir[a]; fir[a]=st;
 } 
void dfs(int u,int fa)
{
    d[u]=d[fa]+1; f[u][0]=fa;
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
    for (int i=20;i>=0;i--) 
    if (d[a]<=d[b]-(1<<i)) b=f[b][i];
    if (a==b) return a;
    for (int i=20;i>=0;i--)
    if (f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
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
    memset(fir,-1,sizeof(fir));
    for (int i=1;i<=n-1;i++) scanf("%d%d",&a,&b),add(a,b);
    dfs(1,0);
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