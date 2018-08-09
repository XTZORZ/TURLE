#include <iostream>
#include <cstring>
using namespace std;
int f[160],ans[160],n;
bool b[160],v;
//ifstream cin("line.in");
//ofstream cout("line.out");
void search(int a)
{
//	for (int i=1;i<=2*n;i++) cout<<f[i]<<" ";cout<<endl;
	if (v) return;
	if (a==0) {
		for (int i=1;i<=2*n;i++) ans[i]=f[i],cout<<f[i]<<" "; 
		cout<<endl;
		v=true; return;
	}
	for (int i=1;i<=2*n-1-a;i++)
	if (!b[i]&&!b[i+a+1]&&i+a+1<=2*n)
	{
		b[i]=b[i+a+1]=true;
		f[i]=f[i+a+1]=a;
		search(a-1);
		b[i]=b[i+a+1]=false;
		f[i]=f[i+a+1]=0;
	}
}

int main()
{
	cin>>n;
//for (n=1;n<=23;n++)
{
	if (n%4==1||n%4==2){
		cout<<"No sollution." <<endl;
		return 0;
	}
	memset(f,0,sizeof(f));
	memset(b,0,sizeof(b)); v=false;
	search(n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=2*n;j++)
		if (i==ans[j])
		{
			for (int k=j+1;k<=2*n;k++)
			if (ans[k]==ans[j]) {cout<<i<<" "<<k-j-1<<endl;break;} 
		}
	}
}
	return 0;
}
