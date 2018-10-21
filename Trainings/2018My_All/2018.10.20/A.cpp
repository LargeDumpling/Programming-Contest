/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
long long N,X,e[18],ans=0;
int main()
{
	scanf("%d",&T_T);
	e[0]=1LL;
	for(int i=1;i<=17;i++)
		e[i]=e[i-1]*10LL;
	while(T_T--)
	{
		ans=0;
		scanf("%lld%lld",&N,&X);
		for(int i=1;i<=17;i++) if(X<e[i])
		{
			if((e[i]-X)*i<=N)
			{
				ans+=(e[i]-X);
				N-=(e[i]-X)*i;
				X=e[i];
			}
			else if(N<(e[i]-X)*i)
			{
				if(N%i) ans=-1;
				else ans+=(N/i);
				break;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

