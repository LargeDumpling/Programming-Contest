/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num1[62550],num2[62550],m[62550];
int T_T,n,len1,len2;
int f[62550],g[62550];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		scanf("%d%d%d",&n,&len1,&len2);
		len1++; len2++;
		memset(m,0,sizeof(m));
		for(int i=1;i<=len1;i++)
		{
			scanf("%d",&num1[i]);
			m[num1[i]]=i;
		}
		memset(g,127,sizeof(g));
		for(int i=1;i<=len2;i++)
		{
			scanf("%d",&num2[i]);
			g[f[i]=lower_bound(g+1,g+len1+1,num2[i])-g]=num2[i];
		}
		printf("Case %d: %d\n",cAse,f[len2]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

