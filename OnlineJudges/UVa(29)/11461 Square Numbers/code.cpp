/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-15	File created.
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
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	while(scanf("%d%d",&a,&b)!=-1&&a&&b)
		printf("%d\n",(int)sqrt(b)-(int)sqrt(a-1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

