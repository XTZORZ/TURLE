/*#include <iostream>
using namespace std;
int main()
{
	long long b,p,k;
	cin>>b>>p>>k; long long b1=b;
	long long s=0,tot=0,ans=1;
	b%=k;
	for (int i=1;i<=p;i++)
	ans=(ans*b)%k;
	if (p==0) ans=1;
	cout<<b1<<"^"<<p<<" mod "<<k<<"="<<ans%k<<endl;
	return 0;
 } */
 
// �����������㷨�� 
#include <iostream>
using namespace std;
int main()
{
	long long b,p,k;
	cin>>b>>p>>k; long long bb=b,pp=p;
	long long s=0,mi=1,ans=1;
	b%=k;
	while(p>0)
	{
		if (p&1) ans=ans*b%k;
//		cout<<ans<<endl;
		p/=2;
		b=b*b%k;  //��Ȼ�Ƕ����ƣ�����Ȼ��b���� 
	}
	cout<<bb<<"^"<<pp<<" mod "<<k<<"="<<ans%k<<endl;
	return 0;
 }
 //�߶��㷨�� 

