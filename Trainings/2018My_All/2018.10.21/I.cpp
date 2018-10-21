/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int T_T,n;
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		if(n==2) puts("0 2 1 3");
		else if(n==3) puts("1 4 2 5 3 6");
		else if(n==4) puts("0 6 1 9 3 8 4 10");
		else
		{
			printf("%d %d %d %d",0,2*n-3,1,2*n-4);
			for(int i=2;i<n;i++)
				printf(" %d %d",i,4*n-3-i);
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

