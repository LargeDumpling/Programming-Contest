/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,num[MAXN];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		init();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

