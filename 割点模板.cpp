#include <iostream>
using namespace std;
struct ed{
	int u;
	int nex;
}e[200200];
int n,m,x,y,now,st,dnf[100020],low[100020],fir[100020];
bool ye[100020],v[100020];

void add(int x,int y)
{
	e[++st].u=x; e[st].nex=fir[y]; fir[y]=st;
	e[++st].u=y; e[st].nex=fir[x]; fir[x]=st;
}

void tarjan(int x,int fa)  //fa没别的意思，就是判断是否为根节点 
{
	int son=0;
	dnf[x]=low[x]=++now; v[x]=1;
	for (int i=fir[x];i;i=e[i].nex) 
	{
		int u=e[i].u; 
		if (!v[u]){
			son++; tarjan(u,x),low[x]=min(low[x],low[u]);
			if ((!fa&&son>1)||(fa&&low[u]>=dnf[x])) ye[x]=1;
		}
		else low[x]=min(low[x],dnf[u]); //??
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>x>>y,add(x,y);
	for (int i=1;i<=n;i++)
	if (!dnf[i]) tarjan(i,0);int ans=0;
	for (int i=1;i<=n;i++) ans+=ye[i]; cout<<ans<<endl;
	for (int i=1;i<=n;i++) if (ye[i]) cout<<i<<" ";
	return 0;
} 
