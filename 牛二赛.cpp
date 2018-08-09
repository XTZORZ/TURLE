#include<cstdio>
#include<cstring>
#define maxn 105
int head[maxn],cnt,N,M,topo[maxn][maxn],t,vis[maxn],ans;
//topo[i]存第i次拓扑排序的结果 
struct node{
    int next,to;
}edge[4505];
void add(int u,int v){edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;}
//链式前向星存图 
void dfs(int now,int ran){//参数解释:now为当前节点,ran为第几次拓扑排序 
    vis[now]=1;//标记访问 
    for(int i=head[now];~i;i=edge[i].next){
        if(vis[edge[i].to]==0)dfs(edge[i].to,ran);
    }//访问所有未访问过的子节点 
    topo[ran][t--]=now;//记录拓扑排序结果 
}
int main(){
    memset(head,-1,sizeof(head));//我的链式前向星的head[]从-1开始
    //所以for()中的终止条件为 ~i 
    scanf("%d %d",&N,&M);
    t=N;
    ans=N;//满足条件的点最多有N个 
    for(int i=1,t1,t2;i<=M;++i){
        scanf("%d %d",&t1,&t2);
        add(t1,t2);
    }//建图 
    for(int i=1;i<=N;++i){
        memset(vis,0,sizeof(vis));//每次清空vis 
        t=N; 
        for(int j=i;j<=i+N-1;++j)
        if(vis[(j-1+N)%N+1]==0)dfs((j-1+N)%N+1,i); 
    }
    for(int i=1;i<=N;++i){
    	
    for(int j=1;j<N;++j){
        if(topo[j][i]!=topo[j+1][i]){ans--;break;}
    }//如果在某两次拓扑序列中相同位置的值不同,则该点不能确定 
    }
    for (int i=1;i<=N;i++)
    {

    for (int j=1;j<=N;j++)
	printf("%d ",topo[i][j]);printf("\n");}
    printf("%d",ans);
    return 0;
}
