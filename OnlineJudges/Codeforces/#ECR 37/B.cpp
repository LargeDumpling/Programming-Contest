/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-02	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int T_T,n;
int main()
{
	int til,l,r;
	scanf("%d",&T_T);
	while(T_T--)
	{
		til=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&l,&r);
			if(til<=l)
			{
				printf("%d ",l);
				til=l+1;
			}
			else
			{
				if(r<til)
					printf("0 ");
				else
				{
					printf("%d ",til);
					til++;
				}
			}
		}
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

