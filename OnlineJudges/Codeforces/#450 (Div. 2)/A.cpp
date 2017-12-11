/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-12	File created.
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
	int x;
	a=b=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%*d",&x);
		if(x<0) a++;
		else b++;
	}
	if(min(a,b)<=1) puts("Yes");
	else puts("No");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

