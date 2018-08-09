#include <iostream>
using namespace std;
int f[40000],d[40000],s[40000]; //旗下的战舰数 和 该列总数
int n,m,a,b;
char c;

int abs(int a)
{
	return (a>0)?a:-a;
}

int find(int a)
{
	if (a!=f[a])
	{
		int k=f[a];
		f[a]=find(f[a]);
		d[a]+=d[k];
		return f[a];
	}
	else return f[a];
}

void he(int a,int b)
{
	int f1=find(a),f2=find(b);
	if (f1!=f2)
	{
		f[f1]=f2; d[f1]+=s[f2];
		s[f2]+=s[f1]; s[f1]=0;
	}
}
int main()
{
	cin>>n;
	for (int i=1;i<=30000;i++) f[i]=i,d[i]=0,s[i]=1;
	for (int i=1;i<=n;i++) 
	{
		cin>>c>>a>>b;
		if (c=='M') he(a,b);

		if (c=='C') {
			int f1=find(a),f2=find(b);
//		for (int i=1;i<=n;i++) cout<<f[i]<<" "<<d[i]<<endl;
			if (f1!=f2) cout<<"-1"<<endl;
			else cout<<abs(d[b]-d[a])-1<<endl;
		}
//		for (int i=1;i<=n;i++) cout<<f[i]<<" "<<d[i]<<" "<<s[i]<<endl;
	}
	return 0;
}

/*
4->3,d[3]+=d[4];
5->3 d[3]+=d[5];
2->1 d[1]+=d[2];
3->1 d[1]+=d[3];
*/
