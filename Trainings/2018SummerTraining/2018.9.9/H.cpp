/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-09	File created.
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
int num[MAXN],n,q;
typedef __int128 lll;
lll d[2][M<<1];
void build()
{
	for(int i=1;i<=n;i++)
	{
		d[0][i+M]=num[i];
		d[1][i+M]=d[0][i+M]*(lll)i;
	}
	for(int i=M-1;i;i--)
	{
		d[0][i]=d[0][i<<1]+d[0][i<<1|1];
		d[1][i]=d[1][i<<1]+d[1][i<<1|1];
	}
	return;
}
void change(long long pos,long long x)
{
	d[0][M+pos]=x;
	d[1][M+pos]=d[0][M+pos]*(lll)pos;
	for(int i=(M+pos)>>1;i;i>>=1)
	{
		d[0][i]=d[0][i<<1]+d[0][i<<1|1];
		d[1][i]=d[1][i<<1]+d[1][i<<1|1];
	}
	return;
}
lll query(int k,int L,int R)
{
	lll ans=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans=ans+d[k][L^1];
		if(R&1) ans=ans+d[k][R^1];
	}
	return ans;
}
int main()
{
	int a,b,c;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	build();
	while(q--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			lll ans=query(0,b,c)*(lll)(c+1)-query(1,b,c);
			printf("%lld\n",(long long)ans);
		}
		else if(a==2)
			change(b,c);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

