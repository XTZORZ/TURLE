#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int a;
    int b;
    int num;
}a[200000];
int n,tree[5000],f[200000],t[1000],p;
bool b=0;
bool cmp(node a,node b)
{
    return (a.a<b.a);
}
void add(int o,int l,int r,int x)
{
    if (l==r)
    {
        tree[o]+=1; return;
    }
    if (x<l||x>r) return;
    int mid=(l+r)/2;
    if (x<=mid) add(o*2,l,mid,x);
    if (x>mid) add(o*2+1,mid+1,r,x);
    tree[o]=tree[o*2]+tree[o*2+1];
    return;
}
   
long long query(int o,int l,int r,int x,int y)
{
    if (y<l||x>r) return 0;
    if (x<=l&&r<=y) return tree[o];
    int mid=(l+r)/2;
    return query(o*2,l,mid,x,y)+query(o*2+1,mid+1,r,x,y);
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].a>>a[i].b; a[i].num=i;
    }
    sort(a+1,a+n+1,cmp);  
    int p=0;
    for (int i=1;i<=n;i++)
    {
    //  cout<<a[i].b<<endl;
		if (!b) p=i;
        if (a[i].a==a[i+1].a) //相同跳过增加 
		{
			if (!b) b=true;
			long long k=query(1,0,1000,0,a[i].b-1);
    		f[a[i].num]=k;		
		}
		else   // 不同把以前补上 
		{
			b=false;  
			long long k=query(1,0,1000,0,a[i].b-1);
			for (int j=p;j<=i;j++) add(1,0,1000,a[j].b);
    		f[a[i].num]=k;	
		} 
    }
    for (int i=1;i<=n;i++) cout<<f[i]<<endl;
    return 0;
}
/*
5
0 0
0 200
100 200
200 300
200 300

6
0 12 0 0
0 21 1 -1
0 102 2 -1
0 102 2 2
0 220 4 2
10 200 4 4
*/
