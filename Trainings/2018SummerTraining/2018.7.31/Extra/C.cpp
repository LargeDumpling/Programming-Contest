/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,num[10];
int st[40];
int main()
{
	int x;
	scanf("%d",&T_T);
	while(T_T--)
	{
		st[0]=0;
		scanf("%d",&x);
		if(x==1||x==0) printf("%d\n",x);
		else
		{
			for(int i=9;1<i;i--)
				while(!(x%i))
				{
					st[++st[0]]=i;
					x/=i;
				}
			if(x!=1) puts("-1");
			else
			{
				while(st[0])
					printf("%d",st[st[0]--]);
				putchar('\n');
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

