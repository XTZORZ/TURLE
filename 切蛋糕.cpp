#include <iostream>
#include <climits>
#include <cstdio> 
using namespace std;
int n,m,rr[1000],hh[1000];
long long ans=INT_MAX,minn;
void inline dfs(int r,int h,int d,int now,int v)
{
//if(ans==2599&&d<13)	cout<<r<<" "<<h<<" "<<d<<" "<<now<<" "<<n<<" "<<v+(m-d+1)*r*r*h<<" "<<now+2*(m-d+1)*r*h<<endl;
	if (v>n) return; //if (ans==2599&&d<13)cout<<"!"<<endl; 
	if (v+(m-d+1)*r*r*h<n) return;
	if (now+2*(m-d+1)>ans)return; //cout<<"!!"<<endl;
	if (d==m+1) {
		if (n==v&&now<ans)
		{
			ans=now;//for (int i=1;i<=m;i++) cout<<rr[i]<<" "<<hh[i]<<endl;
//			cout<<now<<endl;
		 } return;
	}//
	if (d==1)
{
	for (register int R=r-1;R>=m;R--) 
	{
		int r2=R*R;
		for (register int H=m;H<=h;H++)
		{
			rr[d]=R; hh[d]=H;
			dfs(R,H,d+1,now+2*R*H+r2,v+r2*H);
		}
	}	
}
	else for (register int R=r-1;R>=m-d+1;R--)
	{
		long long r2=R*R,r1=r*r;
		for (register int H=m-d+1;H<=h-1;H++)
		{
			rr[d]=R; hh[d]=H;
			dfs(R,H,d+1,now+2*R*H+,v+r2*H);
		}
	}
}
int main()
{
	cin>>n;
	cin>>m;
	dfs(28,28,1,0,0);
	cout<<ans<<endl;
	return 0;
}
