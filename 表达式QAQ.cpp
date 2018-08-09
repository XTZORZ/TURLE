#include<cstdio>
const int M=10007,N=100005;
int n,i,u[N],v[N],top,k;
char c[N],sta[N],ans[2*N];
int main()
{
    scanf("%d\n%s",&n,c);
    ans[++k]='.';
    for(i=0;c[i];i++)
    {
        if(c[i]=='('||c[i]=='*')
            sta[++top]=c[i];
        if(c[i]=='+')
        {
            while(sta[top]=='*')
                ans[++k]=sta[top--];
            sta[++top]=c[i];
        }
        if(c[i]==')')
        {
            while(sta[top]!='(')
                ans[++k]=sta[top--];
            top--;
        }
        if(c[i]!='('&&c[i]!=')')
            ans[++k]='.';
    }
    while(top>0)
        ans[++k]=sta[top--];
    for(i=1;i<=k;i++)
    {
        if(ans[i]=='.')
        {
            u[++top]=1;
            v[top]=1;
        }
        if(ans[i]=='*')
        {
            top--;
            u[top]=(u[top+1]*v[top]+u[top]*v[top+1]+u[top]*u[top+1])%M;
            v[top]=v[top]*v[top+1]%M;
        }
        if(ans[i]=='+')
        {
            top--;
            v[top]=(u[top+1]*v[top]+u[top]*v[top+1]+v[top]*v[top+1])%M;
            u[top]=u[top]*u[top+1]%M;
        }
    }
    printf("%d",u[1]);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct dp {
  int zero,one;
}ans[150001];
int len,t = 1;
const int mod = 10007;
string str;
stack<char> s;
inline void dispose(char ch,dp &a,dp &b) {
  if (ch == '+') {
    a.one = (a.one*(b.zero+b.one)+a.zero*b.one)%mod;
    a.zero = a.zero*b.zero%mod;
  } else {
    a.zero = (a.zero*(b.zero+b.one)+a.one*b.zero)%mod;
    a.one = a.one*b.one%mod;
  }
}
int main() {
  //ifstream cin("exp.in",ios :: in);
  //ofstream cout("exp.out",ios :: out);
  cin >> len >> str;
  str += ')';
  ans[1].zero = ans[1].one = 1;
  s.push('(');
  for (int i = 0;i <= len;i++)
    if (str[i] == '(') s.push('(');
    else if (str[i] == ')') {
      for (;s.top() != '(';s.pop(),t--) dispose(s.top(),ans[t-1],ans[t]);
      s.pop();
    } else {
      for (;s.top() <= str[i] && s.top() != '(';s.pop(),t--)
        dispose(s.top(),ans[t-1],ans[t]);
      s.push(str[i]);
      ans[++t].zero = 1;
      ans[t].one = 1;
    }
  cout << ans[1].zero;
  return 0;
}
