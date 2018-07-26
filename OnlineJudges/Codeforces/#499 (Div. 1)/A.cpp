/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int n;
double m,a[MAXN],b[MAXN];
int main()
{
	bool flag=true;
	scanf("%d%lf",&n,&m);
	double om=m;
	for(int i=1;i<=n&&flag;i++)
	{
		scanf("%lf",&a[i]);
		if(a[i]==1)
			flag=false;
	}
	for(int i=1;i<=n&&flag;i++)
	{
		scanf("%lf",&b[i]);
		if(b[i]==1)
			flag=false;
	}
	if(flag)
	{
		m+=m/(b[1]-1);
		for(int i=n;i;i--)
		{
			m+=m/(a[i]-1);
			if(i!=1) m+=m/(b[i]-1);
		}
		printf("%lf",m-om);
	}
	else puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

