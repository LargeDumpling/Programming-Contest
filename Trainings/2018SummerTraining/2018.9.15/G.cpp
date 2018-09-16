/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const long long mod=1000000007;
int T_T,len;
char str[MAXN];
long long calc()
{
	long long n,ans,x;
	len=strlen(str);
	for(int i=len-1;0<=i;i--)
	{
		if('0'<str[i])
		{
			str[i]--;
			break;
		}
		else str[i]='9';
	}
	n=0;
	for(int i=0;i<len;i++)
		n=((n<<1)+(n<<3)+str[i]-'0')%(mod-1);
	ans=1LL;
	x=2LL;
	while(n)
	{
		if(n&1)
			ans=ans*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str);
		printf("%lld\n",calc());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

