/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T;
int n,num[MAXN];
bool cmp(int a,int b) { return a>b; }
int main()
{
	int cnt;
	scanf("%d",&T_T);
	for(int T=1;T<=T_T;T++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		sort(num+1,num+n+1,cmp);
		cnt=0;
		for(int i=1;i<=n;i++)
			if(i%3)
				cnt+=num[i];
		printf("Case #%d: %d\n",T,cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

