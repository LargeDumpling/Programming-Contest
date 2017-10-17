/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-13	File created.
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
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x); srand(x);
	int T_T=rand()%10+1,n,d;
	printf("%d\n",T_T);
	while(T_T--)
	{
		n=rand()%10+91;
		d=1LL*rand()*rand()%1000000000;
		//n=rand()%10+1;
		//d=rand()%11;
		printf("%d %d\n",n,d);
		while(n--)
			printf("%lld ",1LL*rand()*rand()%1000000000);
			//printf("%d ",rand()%11);
		putchar('\n');
	}
	fclose(stdout);
	return 0;
}

