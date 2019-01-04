/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-01-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=15;
int n,a[MAXN],limit;
int main()
{
	bool flag=false;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	limit=1<<n;
	for(int S=0;S<limit;S++)
	{
		int sum=0;
		for(int i=0;i<n;i++)
			if((S>>i)&1) sum+=a[i];
			else sum-=a[i];
		if(sum%360==0)
			flag=true;
	}
	if(flag) puts("YES");
	else puts("NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

