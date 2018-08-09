#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char c;
	int a[30]={0};
	freopen("2.txt","r",stdin);
	while (scanf("%c",&c)==1)
	{
		if (c>='A'&&c<='Z') a[c-'A'+1]++;
	}
	int max=0;
	for (int i=1;i<=26;i++) if (max<a[i]) max=a[i];
	for (int i=max;i>=1;i--)
	{
	  for (int j=1;j<=26;j++)
		{
			if (a[j]==i) 
			{
				printf("* ");
				a[j]--;
			}
			else printf("  ");
		}
	  printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	return 0;
}
