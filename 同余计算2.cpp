#include <iostream>
using namespace std;
int a,b,x,y;
void gcd(int a,int b)
{
//	cout<<a<<" "<<b<<endl;
	if (!b) x=1,y=0; 
	else
	{gcd(b,a%b);
	int k=x;
	x=y; y=k-(a/b)*y;
	return;} 
}

int main()
{
	cin>>a>>b;
	gcd(a,b);
	cout<<(x+b)%b<<endl;
	return 0;
}
