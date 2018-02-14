/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,aa,ab;
int main()
{
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(i==1||aa*b<ab*a)
		{
			aa=a;
			ab=b;
		}
	}
	printf("%lf",(double)aa*m/ab);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

