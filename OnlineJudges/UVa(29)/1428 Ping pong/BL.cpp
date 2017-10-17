/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int T,n,num[100050];
	long long ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		for(int i=1;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				for(int k=j+1;k<=n;k++)
					if((num[i]<=num[j]&&num[j]<=num[k])||(num[i]>=num[j]&&num[j]>=num[k]))
						ans++;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

