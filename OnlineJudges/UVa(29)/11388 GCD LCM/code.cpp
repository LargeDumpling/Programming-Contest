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
	int T_T,a,b;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&a,&b);
		if(b%a) puts("-1");
		else printf("%d %d\n",a,b);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

