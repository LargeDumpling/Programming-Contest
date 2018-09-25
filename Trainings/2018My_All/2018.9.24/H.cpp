/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
int T_T,n,m,p;
int A[MAXN],B[MAXN],pre[MAXN],ans;
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1)
			return;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void get_fail()
{
	pre[1]=-1;
	for(int i=2,j=0;i<=m;i++)
	{
		while(j&&B[i]!=B[j+1]) j=pre[j];
		if(B[i]==B[j+1]) j++;
		pre[i]=j;
	}
	return;
}
void KMP(int st)
{
	for(int j=0;st<=n;st+=p)
	{
		while(j&&A[st]!=B[j+1]) j=pre[j];
		if(A[st]==B[j+1])
		{
			j++;
			if(j==m)
			{
				j=pre[j];
				ans++;
			}
		}
	}
	return;
}
int main()
{
	read1n(T_T);
	for(int T=1;T<=T_T;T++)
	{
		ans=0;
		read1n(n);
		read1n(m);
		read1n(p);
		for(int i=1;i<=n;i++)
			read1n(A[i]);
		for(int i=1;i<=m;i++)
			read1n(B[i]);
		get_fail();
		for(int i=1;i<=p;i++)
			KMP(i);
		printf("Case #%d: %d\n",T,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

