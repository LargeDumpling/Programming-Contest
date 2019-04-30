/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int T_T,n,m,k;
int num[1050],qua[1050];
int main()
{
	int x,cnt;
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(num,0,sizeof(num));
		memset(qua,0,sizeof(qua));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			num[x]++;
			if(2*i<=n)
				qua[x]++;
		}
		cnt=0;
		for(int i=1;i<=m;i++)
			cnt+=min(qua[i],num[i]/k);
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

