/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007LL;
int T_T;
long long A,B,C,D,P,n,F1,F2;
int main()
{
	freopen("Problem.in","r",stdin);
	freopen("BL.out","w",stdout);
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&A,&B,&C,&D,&P,&n);
		F1=A;
		F2=B;
		if(n==1) printf("%lld\n",A);
		else if(n==2) printf("%lld\n",B);
		else
		{
			long long tem;
			for(int i=3;i<=n;i++)
			{
				tem=(C*F1%mod+D*F2%mod+(P/i))%mod;
				F1=F2;
				F2=tem;
			}
			printf("%lld\n",F2);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

