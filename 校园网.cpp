#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
struct ed{
    int u;
    int nex;
}e[40001],e1[40001];
stack<int> q;
int n,a,st,now,cnt,chu[40001],ru[40001],fir1[40001],fir[40001],dnf[40001],low[40001],col[40001];
bool v[40001];

void add(int u,int v)
{
    e[++st].u=v; e[st].nex=fir[u]; fir[u]=st;
}

void add1(int u,int v)
{
    e1[++st].u=v; e1[st].nex=fir1[u]; fir1[u]=st;
}

void tarjan(int x)
{
    dnf[x]=low[x]=++now; v[x]=1;
    q.push(x);
    for (int i=fir[x];i;i=e[i].nex)
    {
        int u=e[i].u;
        if (!dnf[u]) tarjan(u),low[x]=min(low[x],low[u]);
        else if (v[u]) low[x]=min(low[x],low[u]);	
    }
    if (low[x]==dnf[x])
    {
        cnt++; v[x]=0; col[x]=cnt; //cout<<x<<"!::"<<cnt<<endl;
        while (q.top()!=x)
        {
            int k=q.top(); q.pop();
            v[k]=0; col[k]=cnt;
        }  q.pop(); 
    }
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) { 
        while (1) {
            cin>>a; if (!a) break;
            add(i,a);
    	}
    }
    
    for (int i=1;i<=n;i++) if (!dnf[i]) tarjan(i); 
    st=0;
//	for (int i=1;i<=n;i++) cout<<col[i]<<" ";
    for (int i=1;i<=n;i++)
    for (int j=fir[i];j;j=e[j].nex) 
        if (col[i]!=col[e[j].u]) chu[col[i]]=1,ru[col[e[j].u]]=1,add1(col[i],col[e[j].u]);
    int ans=0,ans2=0;
    for (int i=1;i<=cnt;i++) {
    if (!ru[i]) ans++; if (!chu[i]) ans2++;} //chu du?????
    //具体还是不懂，只知道是出边为0加一条边到入度为0的点上，两者去较大值 
    if (cnt==1) {cout<<"1"<<endl<<"0"<<endl; return 0;}
    cout<<ans<<endl;
    cout<<max(ans,ans2)<<endl;
    return 0;
}
