/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T;
long long n,ans;
char str[MAXN];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str+1);
		n=strlen(str+1);
		ans=0;
		for(long long i=1;i<=n;i++)
		{
			if(i!=1)
			{
				ans+=(i-1LL)*(n-i+1LL);
				if(str[i]==str[i-1])
					ans+=(i-1LL)*(n-i+1LL);
			}
			ans+=(n-i+1LL);
			if(str[i]=='0')
				ans+=(n-i+1LL);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

