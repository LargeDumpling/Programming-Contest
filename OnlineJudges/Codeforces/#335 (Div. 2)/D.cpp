/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int A[100050],B[100050],num[100050],n,m,mIn,mAx,a,b;
int main()
{
	mIn=2147483647;
	mAx=-2147483647;
	scanf("%d%d",&n,&m);
	for(int i=0;i<100050;i++) num[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&A[i],&B[i]);
		if(B[i]) mAx=max(mAx,A[i]);
		else mIn=min(mIn,A[i]);
	}
	if(mAx>mIn) printf("-1");
	else
	{
		int cnt=n;
		a=1,b=2;
		for(int i=1;i<=m;i++)
		{
			if(B[i])
			{
				printf("%d %d\n",cnt-1,cnt);
				cnt--;
			}
			else
			{
				printf("%d %d\n",a,a+b);
				if(a+b==n)
				{
					b++;
					a=1;
				}
				else a++;
			}
		}
	}
	return 0;
}

