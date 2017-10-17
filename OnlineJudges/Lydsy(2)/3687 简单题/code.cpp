/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bitset>
#include<algorithm>
using namespace std;
bitset<2000050>a;
int n,ans,x;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	a[0]=1;
	while(n--)
	{
		scanf("%d",&x);
		a^=(a<<x);
	}
	int ans=0;
	for(int i=0;i<=2000000;i++)if(a[i])ans^=i;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

