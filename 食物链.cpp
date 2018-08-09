#include <iostream>  //带权并查集 题解 
using namespace std;
int f[100000],re[100000];  //0-->同种动物，1-->捕食关系，2-->被捕食关系。
int n,m,a,b,p,ans=0;

int find(int a)
{
	int fa=f[a];
	if (a!=fa) {
		f[a]=find(fa);
		re[a]=(re[a]+re[fa])%3;   //压缩路径时权值忘转了
		//SB啊，路径转移放return后面！！！ 
		//即使不放return后面，也是要先find更新后面的路径的！ 
		return f[a];
	}
	else return fa;
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) f[i]=i,re[i]=0;
	for (int i=1;i<=m;i++)
	{
		cin>>p>>a>>b;
		if ((a>n||b>n)||(p==2&&a==b)) {   //两种白痴情况 
			ans++; continue;
		}
		if (p==1)  //对关系1讨论 
		{
			int f1=find(a),f2=find(b);
			if (f1==f2&&re[a]!=re[b])  //判断是否在同一棵树及两者是否为同种动物。 
			{
//				cout<<"YES?"<<endl; 
				ans++; continue;
			}
			else if(f1!=f2)
			{
//				cout<<a<<" "<<re[a]<<" "<<b<<" "<<re[b]<<endl;
				f[f1]=f2; re[f1]=(3-re[a]+re[b])%3;   //合并 
			}
		}
		if (p==2)  //对关系2讨论 
		{
			int f1=find(a),f2=find(b);
			if (f1==f2) 
			{
				int rela=(re[a]-re[b]+3)%3;  //用两个节点与父亲的关系推出两者关系 
//				cout<<f1<<" "<<re[a]<<" "<<re[b]<<" "<<rela<<endl;
				if (rela!=1) {
//					cout<<"HERE?"<<endl;
					ans++; continue;
				}
			}
			else {
				int f1=find(a),f2=find(b);
				f[f1]=f2; re[f1]=(3-re[a]+re[b]+1)%3;   //合并 
			}
		}
	}
//	for (int i=1;i<=n;i++)
	//cout<<f[i]<<" "<<re[i]<<endl;
	cout<<ans<<endl;
	return 0;
}
/*
4 5
1 1 3
2 2 4
2 3 2
1 1 4
2 2 1

4 5
2 1 2
2 2 3
2 3 1
2 4 2
2 4 3

*/


