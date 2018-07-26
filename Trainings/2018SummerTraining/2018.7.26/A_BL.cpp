/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=40;
int ans=-1,ansS,c[MAXN][5],C[4],n;
int num[MAXN];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A_BL.out","w",stdout);
	int limit,cnt[5];
	bool flag;
	scanf("%d",&n);
	limit=(1<<n);
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&c[i][j]);
	for(int i=0;i<4;i++)
		scanf("%d",&C[i]);
	for(int S=0;S<limit;S++)
	{
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++) if((S>>i)&1)
			for(int j=0;j<5;j++)
				cnt[j]+=c[i][j];
		flag=true;
		for(int i=0;i<4&&flag;i++) if(C[i]<cnt[i])
			flag=false;
		if(flag&&ans<cnt[4])
		{
			ans=cnt[4];
			ansS=S;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

