#include <iostream>  //��Ȩ���鼯 ��� 
using namespace std;
int f[100000],re[100000];  //0-->ͬ�ֶ��1-->��ʳ��ϵ��2-->����ʳ��ϵ��
int n,m,a,b,p,ans=0;

int find(int a)
{
	int fa=f[a];
	if (a!=fa) {
		f[a]=find(fa);
		re[a]=(re[a]+re[fa])%3;   //ѹ��·��ʱȨֵ��ת��
		//SB����·��ת�Ʒ�return���棡���� 
		//��ʹ����return���棬Ҳ��Ҫ��find���º����·���ģ� 
		return f[a];
	}
	else return fa;
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) f[i]=i,re[i]=0;
	for (int i=1;i<=m;i++)
	{
		cin>>p>>a>>b;
		if ((a>n||b>n)||(p==2&&a==b)) {   //���ְ׳���� 
			ans++; continue;
		}
		if (p==1)  //�Թ�ϵ1���� 
		{
			int f1=find(a),f2=find(b);
			if (f1==f2&&re[a]!=re[b])  //�ж��Ƿ���ͬһ�����������Ƿ�Ϊͬ�ֶ�� 
			{
//				cout<<"YES?"<<endl; 
				ans++; continue;
			}
			else if(f1!=f2)
			{
//				cout<<a<<" "<<re[a]<<" "<<b<<" "<<re[b]<<endl;
				f[f1]=f2; re[f1]=(3-re[a]+re[b])%3;   //�ϲ� 
			}
		}
		if (p==2)  //�Թ�ϵ2���� 
		{
			int f1=find(a),f2=find(b);
			if (f1==f2) 
			{
				int rela=(re[a]-re[b]+3)%3;  //�������ڵ��븸�׵Ĺ�ϵ�Ƴ����߹�ϵ 
//				cout<<f1<<" "<<re[a]<<" "<<re[b]<<" "<<rela<<endl;
				if (rela!=1) {
//					cout<<"HERE?"<<endl;
					ans++; continue;
				}
			}
			else {
				int f1=find(a),f2=find(b);
				f[f1]=f2; re[f1]=(3-re[a]+re[b]+1)%3;   //�ϲ� 
			}
		}
	}
//	for (int i=1;i<=n;i++)
	//cout<<f[i]<<" "<<re[i]<<endl;
	cout<<ans<<endl;
	return 0;
}
/*
4 5
1 1 3
2 2 4
2 3 2
1 1 4
2 2 1

4 5
2 1 2
2 2 3
2 3 1
2 4 2
2 4 3

*/


