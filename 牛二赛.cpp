#include<cstdio>
#include<cstring>
#define maxn 105
int head[maxn],cnt,N,M,topo[maxn][maxn],t,vis[maxn],ans;
//topo[i]���i����������Ľ�� 
struct node{
    int next,to;
}edge[4505];
void add(int u,int v){edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;}
//��ʽǰ���Ǵ�ͼ 
void dfs(int now,int ran){//��������:nowΪ��ǰ�ڵ�,ranΪ�ڼ����������� 
    vis[now]=1;//��Ƿ��� 
    for(int i=head[now];~i;i=edge[i].next){
        if(vis[edge[i].to]==0)dfs(edge[i].to,ran);
    }//��������δ���ʹ����ӽڵ� 
    topo[ran][t--]=now;//��¼���������� 
}
int main(){
    memset(head,-1,sizeof(head));//�ҵ���ʽǰ���ǵ�head[]��-1��ʼ
    //����for()�е���ֹ����Ϊ ~i 
    scanf("%d %d",&N,&M);
    t=N;
    ans=N;//���������ĵ������N�� 
    for(int i=1,t1,t2;i<=M;++i){
        scanf("%d %d",&t1,&t2);
        add(t1,t2);
    }//��ͼ 
    for(int i=1;i<=N;++i){
        memset(vis,0,sizeof(vis));//ÿ�����vis 
        t=N; 
        for(int j=i;j<=i+N-1;++j)
        if(vis[(j-1+N)%N+1]==0)dfs((j-1+N)%N+1,i); 
    }
    for(int i=1;i<=N;++i){
    	
    for(int j=1;j<N;++j){
        if(topo[j][i]!=topo[j+1][i]){ans--;break;}
    }//�����ĳ����������������ͬλ�õ�ֵ��ͬ,��õ㲻��ȷ�� 
    }
    for (int i=1;i<=N;i++)
    {

    for (int j=1;j<=N;j++)
	printf("%d ",topo[i][j]);printf("\n");}
    printf("%d",ans);
    return 0;
}
