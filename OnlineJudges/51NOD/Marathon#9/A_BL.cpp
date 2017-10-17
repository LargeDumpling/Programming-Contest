/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[100050];
const int mod=1e9+7;
long long ans=0;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A_BL.out","w",stdout);
	scanf("%d",&n);
	int F[100050],sum;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		F[i]=i;
	}
	do
	{
		sum=0;
		for(int i=0;i<n;i++,sum++)
			if(num[F[i]]>i)break;
		ans=(ans+sum)%mod;
	}while(next_permutation(F,F+n));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

