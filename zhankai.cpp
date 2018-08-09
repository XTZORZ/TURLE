#include <iostream>
#include <cstring>
using namespace std;
int p1,p2,p3;
char c1,c2;
string s,s1;
bool check(char c1,char c2)
{
	if ((c1>='a'&&c1<='z')&&(c2>='a'&&c2<='z')||(c1>='A'&&c1<='Z')&&(c2>='A'&&c2<='Z')) return true;
	else return false;
}
bool checkk(char c1,char c2)
{
if ((c1>='0'&&c1<='9')&&(c2>='0'&&c2<='9')) return true;
	else return false;
}
string go(int a,int b,int c,char c1,char c2)
{
	s1="";
	if (c==1)
	{
		for (int i=c1+1;i<=c2-1;i++)
		for (int j=1;j<=b;j++)
			if (a==1) s1+=tolower((char)i);
			else if (a==2) s1+=toupper((char)i);
			else if (a==3) s1+='*';
	}
	else if (c==2)
	{
		for (int i=c2-1;i>=c1+1;i--)
		for (int j=1;j<=b;j++)
			if (a==1) s1+=tolower((char)i);
			else if (a==2) s1+=toupper((char)i);
			else if (a==3) s1+='*';
	}
	return s1;
}
string go1(int a,int b,int c,char c1,char c2)
{
	s1="";
	if (c==1)
	{
		for (int i=c1+1;i<=c2-1;i++)
		for (int j=1;j<=b;j++)
			if (a==3) s1+='*';
			else s1+=(char)i;
	}
	else if (c==2)
	{
		for (int i=c2-1;i>=c1+1;i--)
		for (int j=1;j<=b;j++)
			if (a==3) s1+='*';
			else s1+=(char)i;
	}
	return s1;

}
int main()
{
	cin>>p1>>p2>>p3;
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='-') 
		{
			c1=s[i-1]; c2=s[i+1];
			if (c1<c2&&check(c1,c2)) cout<<go(p1,p2,p3,c1,c2);
			else if (c1<c2&&checkk(c1,c2)) cout<<go1(p1,p2,p3,c1,c2);
			else cout<<'-';
		}
		else cout<<s[i];
	}
	return 0;
}
