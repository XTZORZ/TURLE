//#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
struct no{
	int w;
	int s[2];
	int sz;
	int sum;
	int fa;
}e[300000];
int n,m,st,root;
int a[300000],b[300000];

void update(int x)
{
	e[x].sz=e[e[x].s[0]].sz+e[e[x].s[1]].sz+e[x].sum;
}



int findf(int x)   //求自己！！和自己的爹！！的父子关系 
{
	return (e[e[x].fa].s[1]==x);//如果自己的爹！的儿子！是自己！ 
}

void ronate(int x)
{
	int fx=e[x].fa,ffx=e[fx].fa;
	int gx=findf(x),ggx=findf(fx);
	int sx=e[x].s[!gx];
	e[fx].s[gx]=sx; e[sx].fa=fx;
	e[x].s[!gx]=fx; e[fx].fa=x;
	e[ffx].s[ggx]=x; e[x].fa=ffx;
	update(fx); update(x); //ffx不改变，因为都是在里面转的 
	//只有这地方要update!! 
}

void splay(int x)
{
	for (int f;f=e[x].fa;ronate(x))
	if (e[f].fa){  //如果不是根节点儿子的话 
		if (findf(x)==findf(f)) ronate(f);  
		else ronate(x);
//		cout<<f<<" "<<x<<endl;
//		check();
	}
	
	root=x; //重要！！上旋改变根节点了！！ 
}

int ask(int k)
{
	int now=root;
	while (true)
	{
		int s=e[e[now].s[0]].sz+e[now].sum;
		if (k<=s&&k>e[e[now].s[0]].sz) {
			splay(now);
//			update(now);  
			return e[now].w;  //比左边多，比左边加自己个数小 
			//要先判断是否为答案？ 
		}
		else if (k>s) k-=s,now=e[now].s[1];  //大了 	 
		else now=e[now].s[0];  //小了 
	}
}

void add(int x)
{
	if (!st)
	{
		e[++st].w=x; e[st].fa=0; e[st].sum++,e[st].sz++;
		root=1; return;
	}  //无节点 
	int now=root;
	while (true)
	{
		e[now].sz++;  //对所有节点更新 
		if (e[now].w==x) {
			e[now].sum++;
			
//			update(e[now].fa); update(now); 
//			↑对于BST，不用update因为 只是更新父亲，没有祖宗 
			splay(now);
			return;
		}  //重复 
		int nex=0;	
//		
		nex=(x<e[now].w)?0:1;
		if (!e[now].s[nex])
		{
			e[++st].w=x; e[st].fa=now; e[st].sum=e[st].sz=1;
			e[now].s[nex]=st; //check();
//			update(now); update(st); 
			splay(st);
			return;
		}  //从没尝试过的体验 
		now=e[now].s[nex];
	}

}
int main()
{ 
//	freopen("testdata.in","r",stdin);
//	freopen("2.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int j=1;j<=m;j++) scanf("%d",&b[j]);
	int p=1;
	for (int i=1;i<=n;i++)
	{
		add(a[i]); //check();
//		cout<<a[i]<<endl;
		while (b[p]==i) printf("%d\n",ask(p)),p++;
		
	 } 
	/* */
	 return 0;
}

