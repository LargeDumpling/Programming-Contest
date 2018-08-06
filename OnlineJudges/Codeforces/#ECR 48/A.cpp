/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
	int x,rem,cnt;
	scanf("%d%d",&n,&m);
	rem=m;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		scanf("%d",&x);
		if(rem<=x)
		{
			x-=rem;
			cnt++;
			cnt+=x/m;
			rem=m-x%m;
		}
		else rem-=x;
		printf("%d ",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

