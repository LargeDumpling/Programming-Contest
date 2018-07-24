/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int M=32768;
int sum[M<<1];
void change(int p,int x)
{
	for(p+=M;p;p>>=1)
		sum[p]+=x;
	return;
}
int query(int L,int R)
{
	int ans=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans+=sum[L^1];
		if(R&1) ans+=sum[R^1];
	}
	return ans;
}
int main()
{
	int left,k,st=0;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	left=n;
	for(int i=1;i<=n;i++,left--)
	{
		k=m%left+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

