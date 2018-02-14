/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
int main()
{
	freopen("tabs.in","r",stdin);
	int n,k,cnt;
	scanf("%d",&T_T);
	while(T_T-->0)
	{
		cnt=0;
		scanf("%d%d",&n,&k);
		if(1<k) cnt++;
		if(k<n) cnt++;
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

