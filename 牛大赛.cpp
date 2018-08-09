#include <iostream>
#include <climits>
#include <cstring>
#include <stack>
#include<queue>
using namespace std;
struct node{
	int v;
	int next;	
}e[50000];
int n,m,a,b,now,tot,fir[200],t[200][200],rd[200],rd1[200];
bool g[200][200],v[200]; 
stack<int> q;
void add(int a,int b,int i)
{
	e[i].v=b; e[i].next=fir[a]; fir[a]=i;
 } 
int main()
{
	cin>>n>>m;
	int anss=n;
	for (int i=1;i<=m;i++) cin>>a>>b,add(a,b,i),rd1[b]++,rd[b]++;
	for (int i=1;i<=n;i++)
	{
		int now=0;
		while (!q.empty()) q.pop();
		for (int j=i;j<=i+n-1;j++)  if (!rd[(j+n-1)%n+1]) dfs((j+n-1)%n+1);
		while (!q.empty())
		{
			
			int num=q.top(); q.pop(); 
			t[i][++now]=num; 
			for (int j=fir[num];j>0;j=e[j].next)  {
				int v=e[j].v;
				rd[v]--; 
				if (!rd[v]) q.push(v);
			}
		}
		for (int j=1;j<=n;j++) rd[j]=rd1[j];
	}
	for (int i=1;i<=n;i++) 
	{
	for (int j=1;j<=n;j++) cout<<t[i][j]<<" ";
	cout<<endl;
	}
	memset(v,0,sizeof(v));
    for (int i=1;i<=n-1;i++)
        for (int j=1;j<=n;j++) if (!v[j]&&t[i][j]!=t[i+1][j]) anss--,v[j]=true;
    cout<<anss<<endl;
//	for (int i=1;i<=n;i++) cout<<rd[i]<<" ";
	return 0;
}
