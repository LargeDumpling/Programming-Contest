/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-06	File created.
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
	int T=rand()%5+1;
	while(T--)
	{
		int n=rand()%5+1;
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
		{
			int lenth=rand()%5+1;
			for(int i=0;i<lenth;i++) putchar(rand()%26+'a');
			putchar('\n');
		}
	}
	fclose(stdout);
	return 0;
}

