/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long f[105][64],k,n;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int ans;
	memset(f,0,sizeof(f));
	for(int i=1;i<=100;i++)
		for(int j=1;j<=63;j++)
			f[i][j]=f[i-1][j-1]+1+f[i][j-1];
	while(scanf("%lld%lld",&k,&n)&&k&&n)
	{
		ans=-1;
		for(int i=1;i<=63;i++)
			if(f[k][i]>=n)
			{
				ans=i;
				break;
			}
		if(ans<0)puts("More than 63 trials needed.");
		else printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

