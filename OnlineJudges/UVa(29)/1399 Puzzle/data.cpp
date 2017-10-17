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
	int T=rand()%100+1;
	printf("%d\n",T);
	while(T--)
	{
		int n=rand()%26+1,s=rand()%1000+1;
		printf("%d %d\n",n,s);
		for(int i=1;i<=s;i++)
		{
			int lenth=rand()%50+1;
			for(int j=0;j<lenth;j++) putchar(rand()%n+'A');
			putchar('\n');
		}
	}
	fclose(stdout);
	return 0;
}

