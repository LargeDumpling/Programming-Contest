/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	int x; sscanf(argv[1],"%d",&x); srand(x);
	freopen("H.in","w",stdout);
	int T_T=rand()%10+1;
	printf("%d\n",T_T);
	while(T_T--)
	{
		int n=rand()%10+1;
		printf("%d\n",n);
		while(n--)
			putchar('0'+rand()%10);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

