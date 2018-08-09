// luogu-judger-enable-o2
#include <iostream>
#include <climits>
using namespace std;
int hang[100][10],lie[100][10],gong[10][10][10];
int tu[10][10]={{0,0,0,0,0,0,0,0,0,0},
{0,6,6,6,6,6,6,6,6,6},
{0,6,7,7,7,7,7,7,7,6},
{0,6,7,8,8,8,8,8,7,6},
{0,6,7,8,9,9,9,8,7,6},
{0,6,7,8,9,10,9,8,7,6},
{0,6,7,8,9,9,9,8,7,6},
{0,6,7,8,8,8,8,8,7,6},
{0,6,7,7,7,7,7,7,7,6},
{0,6,6,6,6,6,6,6,6,6}},cs[10][10],anss,ans[10][10],now[10][10][10],minn=INT_MAX,minj,mini;

int q(int n)
{
    if (n%3==0) return n/3;
    if (n%3!=0) return n/3+1;
}
bool ok()
{
    for (int i=1;i<=9;i++)
    for (int j=1;j<=9;j++) if (!ans[i][j]) return false;
    return true;
}

int jisuan()
{
    int kk=0;
//	cout<<endl;
    for (int i=1;i<=9;i++)	{//	cout<<endl;	
    for (int j=1;j<=9;j++) 
    //	cout<<ans[i][j]<<" ",
    kk+=tu[i][j]*ans[i][j];}
    return kk;
}
void search(int x,int y)
{
    if (ok()) 
    {
        anss=max(anss,jisuan()); return;
    }
    
    for (register int i=1;i<=now[x][y][0];i++)
    {
        bool f=false; 
        ans[x][y]=now[x][y][i];  int k=ans[x][y];
        int k1=q(x),k2=q(y);		
        hang[x][k]++,lie[y][k]++,gong[k1][k2][k]++;
        minn=INT_MAX;
        for (register int i=1;i<=9;i++)
        {
        for (register int j=1;j<=9;j++)
        if (!ans[i][j]){
            now[i][j][0]=0;
            for  (register int k=1;k<=9;k++) if (!hang[i][k]&&!lie[j][k]&&!gong[q(i)][q(j)][k]) now[i][j][0]++,now[i][j][now[i][j][0]]=k;
            if (now[i][j][0]==0) 
            {	
                //cout<<"WTF"<<i<<" "<<j<<endl;
                f=true; break;
                return;
            }
            else if (now[i][j][0]<minn) minn=now[i][j][0],mini=i,minj=j;
        }
        if (f) break;
        }
        if (!f) search(mini,minj);
        k1=q(x),k2=q(y);		
        hang[x][k]--,lie[y][k]--,gong[k1][k2][k]--;
        ans[x][y]=0; 
    }
}
int main()
{
    for (int i=1;i<=9;i++)
    for (int j=1;j<=9;j++)
    {
        cin>>cs[i][j];
        int k=cs[i][j];
        ans[i][j]=k;
        int k1=q(i),k2=q(j);		
        hang[i][k]++,lie[j][k]++,gong[k1][k2][k]++;
    }  //chushihua
    
    for (register int i=1;i<=9;i++)
    for (register int j=1;j<=9;j++)
    if (!ans[i][j]){
        for (int k=1;k<=9;k++) if (!hang[i][k]&&!lie[j][k]&&!gong[q(i)][q(j)][k]) now[i][j][0]++,now[i][j][now[i][j][0]]=k;
        if (now[i][j][0]<minn) minn=now[i][j][0],mini=i,minj=j;
        
    }

    search(mini,minj);
    if (anss==0) cout<<"-1"<<endl;
    else cout<<anss<<endl;
    return 0;
}
