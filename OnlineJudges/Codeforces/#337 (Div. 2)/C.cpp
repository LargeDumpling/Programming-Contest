/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
bool ans[550][550];
void updata(int x)
{
	int sz=1<<(x-1);
	for(int i=1;i<=sz;i++)
	{
		for(int j=0;j<sz;j++)
		{
			ans[i+sz][j]=ans[i][j];
			ans[i+sz][j+sz]=ans[i][j]^true;
			ans[i][j+sz]=ans[i][j];
		}
	}
	return;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&n);
	int limit=1<<n;
	ans[0][0]=0;
	for(int i=1;i<=n;i++)
		updata(i);
	for(int i=1;i<=limit;i++)
	{
		for(int j=0;j<limit;j++)printf("%c",ans[i][j]?'*':'+');
		putchar('\n');
	}
	return 0;
}

