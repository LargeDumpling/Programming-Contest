/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x); srand(x);
	int T_T=10,n,len;
	while(T_T--)
	{
		printf("%d\n",n=rand()%5+1);
		while(n--)
		{
			len=rand()%5+1;
			while(len--)
				if(rand()&1) putchar('B');
				else putchar('G');
			putchar('\n');
		}
	}
	putchar('0');
	fclose(stdout);
	return 0;
}

