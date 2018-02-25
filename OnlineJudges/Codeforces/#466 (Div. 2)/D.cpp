/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,A[MAXN],ll=-2147483647,rr=2147483647,mIn,mAx;
char B[MAXN];
void calc(int i)
{
	mIn=2147483647;
	mAx=-2147483647;
	for(int j=i-4;j<=i;j++)
	{
		mIn=min(mIn,A[j]);
		mAx=max(mAx,A[j]);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	scanf("%s",B+1);
	for(int i=5;i<=n;i++)
	{
		if(B[i-1]=='1'&&B[i-2]=='1'&&B[i-3]=='1'&&B[i-4]=='1'&&B[i]=='0')
		{
			calc(i);
			rr=min(rr,mIn);
		}
		else if(B[i-1]=='0'&&B[i-2]=='0'&&B[i-3]=='0'&&B[i-4]=='0'&&B[i]=='1')
		{
			calc(i);
			ll=max(ll,mAx);
		}
	}
	printf("%d %d",max(ll+1,-1000000000),min(rr-1,1000000000));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

