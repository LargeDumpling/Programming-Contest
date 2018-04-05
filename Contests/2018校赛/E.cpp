/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int T_T,n;
char str[MAXN];
int st[MAXN];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		st[0]=0;
		scanf("%s",str);
		for(int i=0;i<n;i++)
		{
			st[++st[0]]=str[i]-'0';
			while(1<st[0]&&st[st[0]-1]==0&&st[st[0]]==1) st[0]-=2;
		}
		printf("%.3lf\n",(double)st[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

