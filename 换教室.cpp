#include<algorithm>
#include <iostream>
#include <climits>
#include <iomanip>
#include <cstdio>
using namespace std;
int n,m,v,e;
int c[4001],d[4001],p[3],a,b,w;
double ans,ans1;
double k[4001];
int g[4001][4001];
bool bl[4001];
double minn(double a,double b)
{
    return (a<b)?a:b;
}

int min(int a,int b)
{
    return (a<b)?a:b;
}

double print(int now)
{
    double anss=0;
    if (now==1) 
    {
        int t=0;
        t=c[p[1]];
        c[p[1]]=d[p[1]];
        
        for (int i=1;i<=n-1;i++) 
          {
          	anss+=g[c[i]][c[i+1]];
        //     cout<<anss<<",";
          } 
        anss=k[p[1]]*anss+(1-k[p[1]])*ans;
        c[p[1]]=t;
      //  cout<<p[1]<<endl;
     //   cout<<fixed<<setprecision(2)<<anss<<endl;
    }
    if (now==2)
    {
        int t=0,t1=0;
        double anss1=0,anss2=0,anss3=0;
        t=c[p[1]]; t1=c[p[2]];
        c[p[1]]=d[p[1]];
        for (int i=1;i<=n-1;i++) 
          {
          	anss1+=g[c[i]][c[i+1]];
          }
        c[p[2]]=d[p[2]];
        for (int i=1;i<=n-1;i++) 
          {
          	anss2+=g[c[i]][c[i+1]];
          } 
        c[p[1]]=t;
        for (int i=1;i<=n-1;i++) 
          {
          	anss3+=g[c[i]][c[i+1]];
          }
        c[p[2]]=t1;
        anss=1.0*k[p[1]]*(1-k[p[2]])*anss1+1.0*(1-k[p[1]])*k[p[2]]*anss3+1.0*k[p[1]]*k[p[2]]*anss2+1.0*(1-k[p[1]])*(1-k[p[2]])*ans;
    //cout<<anss<<" "<<anss1<<" "<<anss2<<" "<<anss3<<endl;
  }
    return anss;
}

void dfs(int now)
{
    double k=4000000;
    if (now>2||now>m) return;
    if (now>0) k=print(now);
    ans1=minn(ans1,k);
   // cout<<k<<endl;
  //  if (k==3) for (int qq=1;qq<=now;qq++) cout<<p[qq]<<" ";
  //  cout<<endl;
    for (int i=1;i<=n;i++) 
    if (!bl[i])
    {
        bl[i]=true;
        p[now+1]=i;
        dfs(now+1);
        bl[i]=false;
    } 
}
int main()
{
    ans1=4000000.0;
    scanf("%d%d%d%d",&n,&m,&v,&e);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	for (int i=1;i<=n;i++) scanf("%lf",&k[i]);
    for (int i=1;i<=v;i++)
    for (int j=1;j<=v;j++) if (i==j) g[i][j]=0;
    else g[i][j]=INT_MAX/2;   
    for (int i=1;i<=e;i++) 
    {
        scanf("%d%d%d",&a,&b,&w);
        g[a][b]=g[b][a]=min(g[a][b],w);	
    }
       
    //chushi hua
    
    for (int q=1;q<=v;q++)
    for (int i=1;i<=v;i++)
    for (int j=1;j<=v;j++)
      if (g[i][q]+g[q][j]<g[i][j]) g[i][j]=g[i][q]+g[q][j];
    /*  for (int i=1;i<=v;i++)
      {
      	for (int j=1;j<=b;j++) cout<<g[i][j]<<" ";
      	cout<<endl;
	  }*/
    for (int i=1;i<=n-1;i++) 
          {
          	ans+=g[c[i]][c[i+1]];
      //        cout<<anss<<",";
          } 
          ans1=ans*1.0; //³õÊ¼ANS 
    dfs(0);
    printf("%.2lf",ans1);
    return 0;
}

