#include <iostream>
#include <queue>
using namespace std;
struct e{
	int num1;
	int num2;
	int w;
};
int n,a[200000],b[200000],st;

struct cmp// жидиЃПЃП 
{
     bool operator()(const e&a, const e&b)
    {
         return a.w>b.w;
    }
};
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    priority_queue<e, vector<e>, cmp> q;
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
        q.push((e){1,i,a[1]+b[i]});
    }
    for (int i=1;i<=n;i++)
    {
    	e t=q.top();
    	cout<<t.w<<" "; q.pop();
    	q.push((e){t.num1+1,t.num2,a[t.num1+1]+b[t.num2]});
	}
    return 0;
}
