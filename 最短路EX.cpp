#include <cstdio>
#include <climits>
#include <queue>
#include <iostream>
#define pr pair<int,int>
#define mp make_pair  //����pair���� 
using namespace std;
struct ed{
	int u;
	int w;
	int next;
}e[400000];

int n,m,st,s,x,y,w,d[300000],fir[300000];
bool v[300000];

priority_queue<pr,vector<pr>,greater<pr> > q;
//pair ά����С���š� 
void dij(int b)
{
	for (int i=1;i<=n;i++) d[i]=INT_MAX/2;
	d[b]=0; q.push(mp(0,b));
	while (!q.empty())
	{
		pr k1=q.top(); int k=k1.second; 
		q.pop(); //���ȶ���ʡȥ�˵�һ��ѭ���� 
		if (v[k]) continue; v[k]=1; //�ж��Ƿ���ӣ�û�������
		//���ȶ���ֻ��Ϊ�˷����ж�dis�Ĺ�ϵ����SPFA�Ķ��в�ͬ 
		//����ֱ����disֱ���жϼ��룬��Ϊ���к�Ч�ԣ� 
//		cout<<k<<endl;
		for(int i=fir[k];i;i=e[i].next)
		{
			int u=e[i].u,w=e[i].w;
			if (d[u]>d[k]+w) {
				d[u]=d[k]+w;
				q.push(mp(d[u],u));
			}
		}
	}
}

void add(int u,int v,int w)
{
	e[++st].u=u; e[st].w=w; e[st].next=fir[v];
	fir[v]=st;
}
int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		add(y,x,w);
	}
	dij(s);
	for (int i=1;i<=n;i++) printf("%d ",d[i]);
	return 0;
}
