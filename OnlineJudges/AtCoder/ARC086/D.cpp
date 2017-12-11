/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[55],mIn=2147483647,mAx=-2147483647;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		mIn=min(mIn,num[i]);
		mAx=max(mAx,num[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

