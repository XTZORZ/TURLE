#include <iostream>
#include <climits>
using namespace std;
int g[20][20],n,m,r,c,ans=INT_MAX,minn;
int ha[20],le[20];
bool he[20],la[20];
int abs(int a)
{
	return (a>0)?a:-a;
}

int print()
{
	int a=0;
	for (int i=1;i<=r;i++)
	for (int j=1;j<=c;j++)
	{
		if (i==1&&j==1) continue;
		else if (i==1) a+=abs(g[ha[i]][le[j]]-g[ha[i]][le[j-1]]);
		else if (j==1) a+=abs(g[ha[i]][le[j]]-g[ha[i-1]][le[j]]);
		else a+=abs(g[ha[i]][le[j]]-g[ha[i-1]][le[j]])+abs(g[ha[i]][le[j]]-g[ha[i]][le[j-1]]);
	}
	/*	if (a==15) 
		{
			for (int i=1;i<=r;i++) cout<<ha[i]<<" ";
			cout<<endl;
			for (int i=1;i<=c;i++) cout<<le[i]<<" ";
			cout<<endl;
			cout<<endl;
		}
	*/
	return a;
}
void dfsl(int l,int now)
{
	if (l==c+1)
	{
		ans=min(ans,print());
	}
	else
	{
		for (int i=now;i<=m;i++) if (!la[i])
		{	
			le[l]=i; la[i]=true;
			dfsl(l+1,i+1);
			la[i]=false;
		}
	}
}
void dfsh(int h,int now)
{
	if (h==r+1)
	{
		dfsl(1,1);
	}
	else
	{
		for (int i=now;i<=n;i++) if (!he[i])
		{
			ha[h]=i; he[i]=true;
			dfsh(h+1,i+1);
			he[i]=false;
			//		for (int i=1;i<=r;i++)
		//	cout<<ha[i]<<" "; cout<<now<<endl;
		}
	}
	return;
}


int main()
{
	cin>>n>>m>>r>>c;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)	cin>>g[i][j];
	dfsh(1,1);
	cout<<ans<<endl;
	return 0;
}
