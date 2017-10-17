/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-17	File created.
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
	int T_T=rand()%5+1;
	printf("%d\n",T_T);
	while(T_T--)
	{
		int n=rand()%1+2,a,b,c;
		printf("%d\n",n);
		while(n--)
		{
			a=rand()%5;
			if(rand()%2) a=-a;
			b=rand()%5;
			if(rand()%2) b=-b;
			printf("%d %d %d\n",a,b,rand()%3+1);
		}
	}
	putchar('0');
	fclose(stdout);
	return 0;
}

