/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("in.txt","w",stdout);
	int T_T=rand()+1,n;
	T_T=13;
	printf("%d\n",T_T);
	while(T_T--)
	{
		n=(rand()+rand())%150000+1;
		n=150000;
		printf("%d\n",n);
		while(n--) putchar('0'+rand()%10);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

