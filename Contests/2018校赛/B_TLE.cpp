/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long mod=1e9+7;
int T_T,len;
char str[10];
long long calc()
{
	long long sum=0,cnt;
	if(len==1) return str[0]-'0';
	int limit=1<<(len-1);
	for(int S=0;S<limit;S++)
	{
		cnt=0;
		for(int i=0;i<len;i++)
		{
			cnt=(cnt*10LL%mod+str[i]-'0')%mod;
			if(i==len-1||((S>>i)&1))
			{
				sum=(sum+cnt)%mod;
				cnt=0;
			}
		}
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		sprintf(str,"%d",n);
		len=strlen(str);
		printf("%lld\n",calc());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

