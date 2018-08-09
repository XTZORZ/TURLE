#include <iostream>
using namespace std;
struct node{
	int date;
	node *next;
}*head,*p,*r,*s;
int n,m;
int main()
{
	cin>>n>>m;
	while (n!=0&&m!=0)
	{
		head=new node;
		head->date=n;
		r=head;
		for (int i=1;i<=n;i++)
		{
			p=new node;
			p->date=i;
			p->next=NULL;
			r->next=p;
			r=p; 
		}
		r->next=head->next;
		r=head;
		int p=0;
		if (m==1) cout<<n<<endl;
		else
	{
		while (head->date!=1)
		{
			p++;
			if (p==m) {
				s=r->next;
				r->next=s->next;
//				free(s);
				head->date--;
				p=1;
			}
		
			r=r->next;	
		}
		cout<<r->date<<endl;
	}
		cin>>n>>m;
	}
	return 0;
}
