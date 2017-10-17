/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int T=rand()%10+1;
	printf("%d\n",T);
	for(int i=1;i<=T;i++)
	{
		int n=rand()%7+1,m=rand()%7+1;
		printf("%d %d\n",n,m);
		n+=m;
		for(int i=1;i<=n;i++)
		{
			int lenth=rand()%7;
			while(lenth--) putchar(rand()%26+'a');
			putchar('\n');
		}
	}
	fclose(stdout);
	return 0;
}

