/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T,n,num[MAXN];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		printf("%d\n",(int)sqrt(abs(num[1]-num[n])));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

