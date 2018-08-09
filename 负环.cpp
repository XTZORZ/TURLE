//#include <iostream>
#include <fstream>
#include <queue>
#include <climits>
using namespace std;
struct ed{
	int w;
	int u;
	int next;
}e[10000];
int n,m,x,y,w,st;
int d[10000],v[10000],s[10000],fir[10000],f[10000];
ifstream cin("1.txt");
ofstream cout("2.txt");
void add(int u,int v,int w)
{
	e[++st].u=u; e[st].w=w; e[st].next=fir[v];
	fir[v]=st;
}

bool spfa(int bb)
{
	d[bb]=0; v[bb]=1; s[bb]=1;
//	
	queue<int> q; q.push(bb); f[bb]=1;
	while (!q.empty())
	{
		int k=q.front(); q.pop(); v[k]=0;
		for (int i=fir[k];i;i=e[i].next)
		{
			
			int u=e[i].u,w=e[i].w;f[u]=1;
			if (d[u]>d[k]+w) 
			{
				d[u]=d[k]+w,s[u]++;
				if (!v[u]) v[u]=1,q.push(u);
				if (s[u]>n) return true;
			}
		
		}
	}
	return false;
}

int main()
{
	int tt=0; cin>>tt; 
while(tt--)
{
//cout<<tt<<endl;
	cin>>n>>m;st=0;
	for (int i=1;i<=n;i++) f[i]=v[i]=s[i]=fir[i]=0,d[i]=INT_MAX/2;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		add(x,y,w);
		if (w>=0) add(y,x,w);
	} int ok=1;
	for (int i=1;i<=n;i++)
	if (!f[i])
	if(spfa(i))
	{
		cout<<"YE5"<<endl; ok=0; break;
	}
	if (ok) cout<<"N0"<<endl;
}
	return 0;
}
