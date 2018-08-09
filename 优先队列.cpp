#include <iostream>
#include <queue>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int> > p;
	int n,x,k=1,w[100]={0};
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>w[i];
		p.push(w[i]);
	}
	while (p.size()<n*4)
	{
		k++;
		for (int i=1;i<=n;i++) p.push(w[i]*k);
	}
	for (int i=1;i<=n*4;i++)
	{
		cout<<p.top()<<" ";
		p.pop();
	}
	return 0;
}
