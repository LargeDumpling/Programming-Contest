/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int get(int x,int digit)
{
	int sum=0;
	for(;x;x/=10)if(x%10==digit)sum++;
	return sum;
}
void solve(int L,int R)
{
	if(L>R)
	{
		L^=R;
		R=L^R;
		L^=R;
	}
	int ans;
	for(int i=0;i<=9;i++)
	{
		ans=0;
		for(int j=L;j<=R;j++)
			ans+=get(j,i);
		printf("%d",ans);
		if(i==9)putchar('\n');
		else putchar(' ');
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int a,b;
	while(scanf("%d%d",&a,&b)!=-1&&a&&b)solve(a,b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

