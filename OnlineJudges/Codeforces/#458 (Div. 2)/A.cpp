/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,ans=-99999999;
bool check(int x) { return 0<=x&&(int)sqrt(x)*(int)sqrt(x)==x; }
int main()
{
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(!check(x))
			ans=max(ans,x);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

