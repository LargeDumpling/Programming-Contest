/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long strcmp(char *A,char *B)
{
	long long ans=1;
	while(*A==*B)
	{
		ans++;
		if(*A=='\0') return ans;
		ans++;
		A++; B++;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	long long ans;
	int n;
	char tex[4050][105];
	for(int cAse=1;scanf("%d",&n)!=-1&&n;cAse++)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex[i]);
			for(int j=1;j<i;j++) ans+=strcmp(tex[i],tex[j]);
		}
		printf("Case %d: %lld\n",cAse,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

