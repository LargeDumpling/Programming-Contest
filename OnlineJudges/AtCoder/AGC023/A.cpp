/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
long long ans=0;
int n;
long long s[MAXN];
int main()
{
	long long cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		s[i]+=s[i-1];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n+1;i++)
	{
		if(i==n+1||s[i]!=s[i-1])
		{
			if(s[i-1]==0) cnt++;
			ans+=(long long)cnt*(cnt-1)/2LL;;
			cnt=1;
		}
		else if(s[i]==s[i-1])
			cnt++;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

