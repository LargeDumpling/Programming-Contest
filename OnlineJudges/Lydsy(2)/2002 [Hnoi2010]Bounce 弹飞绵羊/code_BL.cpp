/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,v[200050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code_BL.out","w",stdout);
	int a,b,order;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&order,&a);
		if(order==1)
		{
			b=0;
			for(int i=a;i<n;i+=v[i]) b++;
			printf("%d\n",b);
		}
		else if(order==2)
		{
			scanf("%d",&b);
			v[a]=b;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

