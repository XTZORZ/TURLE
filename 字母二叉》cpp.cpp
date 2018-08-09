#include <iostream>
using namespace std;

struct tr{
	char ls;
	char rs;
}zimu[30];
int n,s; 
char head;
void print(char o)
{
	cout<<o;
	if (zimu[o-'a'+1].ls) print(zimu[o-'a'+1].ls);
	if (zimu[o-'a'+1].rs) print(zimu[o-'a'+1].rs);
	return;
}
int main()
{
	cin>>n; 
	for (int i=1;i<=n;i++)
	{
		char a,b,c;
		cin>>a>>b>>c;
		if (i==1) head=a;
		if (b!='*')zimu[a-'a'+1].ls=b;
		if (c!='*')zimu[a-'a'+1].rs=c;
	}
	print(head);
	return 0;
} 
