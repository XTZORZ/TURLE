#include <iostream>
#include <stack>
using namespace std;
char c[200000];
stack<char> q;
int n,f1[200000],f2[200000],t;  //1-0,2-1

int main()
{
	cin>>n; t=1;
	for (int i=1;i<=n;i++) cin>>c[i];
	f1[1]=f2[1]=1;
	q.push('('); 
	for (int i=1;i<=n;i++)
	{
	//	cout<<c[i];
		if (c[i]=='(') q.push('(');
		if (c[i]==')')
		{
			while (q.top()!='(') 
			{
				if (q.top()=='*')
				{
					f1[t-1]=(f1[t-1]*(f1[t]+f2[t])+f2[t-1]*f1[t])%10007;
					f2[t-1]=f2[t-1]*f2[t]%10007;
				}
				else {
					f2[t-1]=(f2[t-1]*(f1[t]+f2[t])+f1[t-1]*f2[t])%10007;
					f1[t-1]=f1[t]*f1[t-1]%10007;
				}
				q.pop(); t--;
			}
			q.pop();
		}
		if (c[i]=='+')
		{
			//cout<<"?";
			while (q.top()!='(') 
			{
				if (q.top()=='*')
				{
					f1[t-1]=(f1[t-1]*(f1[t]+f2[t])+f2[t-1]*f1[t])%10007;
					f2[t-1]=f2[t-1]*f2[t]%10007;
				}
				else {
					f2[t-1]=(f2[t-1]*(f1[t]+f2[t])+f1[t-1]*f2[t])%10007;
					f1[t-1]=f1[t]*f1[t-1]%10007;
				}
				q.pop(); t--;
			}
			q.push('+'); f1[++t]=f2[t]=1;
			//cout<<f1[t-1]<<" "<<f2[t-1]<<endl;
		}
		if (c[i]=='*')
		{
			while (q.top()!='('&&q.top()!='+') 
			{
				if (q.top()=='*')
				{
					f1[t-1]=(f1[t-1]*(f1[t]+f2[t])+f2[t-1]*f1[t])%10007;
					f2[t-1]=f2[t-1]*f2[t]%10007;
				}
				q.pop(); t--;
			}
			q.push('*'); f1[++t]=f2[t]=1;
		}
	 }
	 //cout<<f1[1]<<endl;
	//×îºóÒ»²¨£¡ 
			while (q.top()!='(') 
			{
				if (q.top()=='*')
				{
					f1[t-1]=(f1[t-1]*(f1[t]+f2[t])+f2[t-1]*f1[t])%10007;
					f2[t-1]=f2[t-1]*f2[t]%10007;
				}
				else {
					f2[t-1]=(f2[t-1]*(f1[t]+f2[t])+f1[t-1]*f2[t])%10007;
					f1[t-1]=f1[t]*f1[t-1]%10007;
				}
				q.pop(); t--;
			}
	cout<<f1[1]<<endl;
	return 0;
}


