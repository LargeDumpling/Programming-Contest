/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1000000007;
const int MAXL=100050;
int num[3],T_T,n,ans;
char str[MAXL];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(num,0,sizeof(num));
		ans=0;
		scanf("%s",str);
		n=strlen(str);
		for(int i=0;i<n;i++)
			num[str[i]-'0']++;
		for(int i=0;i<n;i++)
		{
			ans=(ans+num[1])%mod;
			num[1]=(num[1]+num[2])%mod;
			if(str[i]=='1') num[1]--;
			else if(str[i]=='2') num[2]--;
			ans=(ans+1LL)%mod;
		}
		ans=((ans+num[1])%mod+(long long)num[1]*(num[1]+1LL)/2LL)%mod;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

