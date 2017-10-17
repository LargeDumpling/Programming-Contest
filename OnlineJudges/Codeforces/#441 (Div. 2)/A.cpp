/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a,b,c;
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&c);
	n--; a=min(a,b);
	if(!n) putchar('0');
	else printf("%d",a<=c?a*n:a+c*(n-1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

