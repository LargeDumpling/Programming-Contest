/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-17	File created.
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
int n,a[MAXN],s,f;
int d[M<<1];
void change(int L,int R,int x)
{
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) d[L^1]+=x;
		if(R&1) d[R^1]+=x;
	}
	return;
}
int query(int x)
{
	int ans=0;
	for(x+=M;x;x>>=1)
		ans+=d[x];
	return ans;
}
int main()
{
	int mAx=-1,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d%d",&s,&f); f--;
	for(int i=1;i<=n;i++)
	{
		if(f<=s) change(1,f,a[i]),change(s,n,a[i]);
		else change(s,f,a[i]);
		s--; f--;
		if(!s) s=n;
		if(!f) f=n;
	}
	for(int i=1;i<=n;i++)
		if(mAx<query(i))
		{
			mAx=query(i);
			ans=i;
		}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

