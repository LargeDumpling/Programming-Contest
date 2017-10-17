/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long min(long long a,long long b){return a<b?a:b;}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long ans,n,k,now,p,y,j;
	while(scanf("%lld%lld",&n,&k)!=-1)
	{
		ans=now=0;
		while(now<n)
		{
			now++;
			y=k%now;
			p=k/now;
			if(p)
			{
				j=min(y/p+1,n-now+1);
				now+=(j-1);
				ans+=j*(y+(y-(j-1)*p))/2;
			}
			else
			{
				j=n-now+1;
				ans+=j*k;
				now+=j;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

