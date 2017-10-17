/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n;
int sz,num[105];
bool G[105][105];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int t;
	char ord[60];
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%s",&n,ord);
		sz=n;
		t=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++,t++)
			{
				if(ord[t]
			}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

