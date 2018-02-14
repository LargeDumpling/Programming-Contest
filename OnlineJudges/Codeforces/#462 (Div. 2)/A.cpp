/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long INF=(1LL<<62)-1LL+(1LL<<62);
int n,m,cnt=0;
long long a[55],b[55],mAx[55];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%I64d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		mAx[i]=-INF;
		for(int j=1;j<=m;j++)
			mAx[i]=max(mAx[i],a[i]*b[j]);
	}
	sort(mAx+1,mAx+n+1);
	printf("%I64d",mAx[n-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

