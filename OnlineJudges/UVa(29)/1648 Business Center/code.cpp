/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int m,n,mIn,a,b;
	while(scanf("%d%d",&m,&n)!=-1)
	{
		mIn=2147483647;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			a+=b;
			mIn=min(mIn,a-((b*m)%a));
		}
		printf("%d\n",mIn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

