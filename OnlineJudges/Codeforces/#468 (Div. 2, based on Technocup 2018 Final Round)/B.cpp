/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a,b;
int main()
{
	int t;
	scanf("%d%d%d",&n,&a,&b);
	a--; b--;
	for(t=1;;t++,a>>=1,b>>=1)
		if((a^1)==b)
			break;
	if((1<<t)==n) printf("Final!");
	else printf("%d",t);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

