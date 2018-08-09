#include <iostream>
#include <climits>
using namespace std;
struct e{
	int w;
	int s[2];
	int sz;
	int sum;
	int fa; 
}e[3000000];
int n,a[100000],st,root;
long long ans=0;

int ff(int x)
{
	return (e[e[x].fa].s[1]==x);
}

void update(int x)
{
	e[x].sz=e[e[x].s[0]].sz+e[e[x].s[1]].sz+e[x].sum;
}

void rotate(int x)
{
	int fx=e[x].fa,ffx=e[fx].fa;
	int gx=ff(x),ggx=ff(fx);
	int sx=e[x].s[!gx];
	e[fx].s[gx]=sx; e[sx].fa=fx;
	e[x].s[!gx]=fx; e[fx].fa=x;
	e[ffx].s[ggx]=x; e[x].fa=ffx;
	update(fx); update(x);
}

void splay(int x)
{
	for (int f;f=e[x].fa;rotate(x))
	if (e[f].fa) rotate((ff(x)==ff(f))?f:x);
	root=x;
}

void add(int x)
{
	if (!st)
	{
		st=root=1;
		e[st].w=x; e[st].fa=0; e[st].s[0]=e[st].s[1]=0;
		e[st].sz=e[st].sum=1; return;
	}
	int now=root;
	while (1)
	{
		e[st].sz++;
		if(e[now].w==x)
		{
			e[st].sum++; splay(now); return; 
		}
		int nex=(x>e[now].w);
		if (!e[now].s[nex])
		{
			e[++st].fa=now; e[st].sum=e[st].sz=1; e[st].w=x;
			e[now].s[nex]=st;
			splay(st);
			return;
		}
		now=e[now].s[nex];
	}
}

int qian(int x) //指第一个小于等于x的数 
{
	int now=root,ans=INT_MIN;
	while (1)
	{
		if (!now) break;
		if (e[now].w==x) return x;
		if (e[now].w<x&&e[now].w>ans) ans=e[now].w;
		if (e[now].w<x) now=e[now].s[1];
		else now=e[now].s[0];
	}
	return ans;
}

int hou(int x)
{
	int now=root,ans=INT_MAX;
	while (1)
	{
		if (!now) break;
		if (e[now].w==x) return x;
		if (e[now].w>x&&e[now].w<ans) ans=e[now].w;
		if (e[now].w>x) now=e[now].s[0];
		else now=e[now].s[1];
	}
	return ans;
}

long long abs(long long x)
{
	return (x>0)?x:-x;
}
int main()
{
	cin>>n; cin>>a[1]; ans+=abs(a[1]);
//	cout<<ans<<endl;
	add(a[1]);
	for (int i=2;i<=n;i++)
	{
		cin>>a[i];
		long long ans1=abs(qian(a[i])-a[i]);
		long long ans2=abs(hou(a[i])-a[i]);
//		cout<<ans1<<" "<<ans2<<endl;
		ans+=min(ans1,ans2);
//		cout<<ans<<endl;
		add(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}

