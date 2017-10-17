/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int A[20050],B[20050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int an,bn,ans;
	while(scanf("%d%d",&n,&m)!=-1&&n&&m)
	{
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		for(int i=1;i<=m;i++)scanf("%d",&B[i]);
		sort(A+1,A+n+1);sort(B+1,B+m+1);
		an=bn=1;ans=0;
		while(an<=n&&bn<=m)
		{
			while(bn<=m&&A[an]>B[bn])bn++;
			if(A[an]<=B[bn]&&bn<=m)
			{
				an++;
				ans+=B[bn++];
			}
		}
		if(an==n+1)printf("%d\n",ans);
		else puts("Loowater is doomed!");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

