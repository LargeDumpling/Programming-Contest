/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int M=131072;
int n,a[MAXN],num[MAXN],d[M<<1];
void change(int p,int x)
{
	for(p=p+M;p;p>>=1)
		d[p]+=x;
	return;
}
int query(int L,int R)
{
	int ans=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans+=d[L^1];
		if(R&1) ans+=d[R^1];
	}
	return ans;
}
int main()
{
	int ans=2147483647,ansn=-2147483647;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[i]=query(a[i]+1,n);
		change(a[i],1);
	}
	memset(d,0,sizeof(d));
	for(int i=n;i;i--)
	{
		if(num[i]==1) change(a[i],1);
		int tem=query(1,a[i]-1)-(int)(num[i]==0);
		if(ansn<tem)
			ansn=tem,ans=a[i];
		else if(ansn==tem)
			ans=min(ans,a[i]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

