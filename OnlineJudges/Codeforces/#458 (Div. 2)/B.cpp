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
const int MAXN=100050;
int n,num[MAXN],mAx=0,ans=0;
int main()
{
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		num[x]^=1;
	}
	for(int i=100000;i;i--)
		if(num[i])
		{
			ans=1;
			break;
		}
	if(ans) puts("Conan");
	else puts("Agasa");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

