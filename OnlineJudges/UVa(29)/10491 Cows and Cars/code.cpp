/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-07	File created.
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
	int a,b,c;
	double fz,fm;
	while(scanf("%d%d%d",&a,&b,&c)!=-1)
	{
		fz=b*(a+b-1);
		fm=(a+b)*(a+b-1-c);
		printf("%.5lf\n",fz/fm);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

