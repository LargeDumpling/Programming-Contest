/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,k,m,x[MAXN],num[MAXN];
int main()
{
	int flag=-1;
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		num[x[i]%m]++;
	}
	for(int i=0;flag==-1&&i<m;i++)
		if(k<=num[i])
			flag=i;
	if(flag!=-1)
	{
		puts("Yes");
		for(int i=1;i<=n&&k;i++)
			if(x[i]%m==flag)
			{
				k--;
				printf("%d ",x[i]);
			}
	}
	else puts("No");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

