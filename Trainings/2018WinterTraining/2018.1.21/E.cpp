/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
char A[MAXN],B[MAXN];
int lenA,lenB,pre[MAXN],mat[MAXN];
int cnt[MAXN];
void get_pre()
{
	pre[0]=-1;
	for(int i=1,j=-1;i<lenB;i++)
	{
		while(0<=j&&B[i]!=B[j+1]) j=pre[j];
		if(B[i]==B[j+1])
			j++;
		pre[i]=j;
	}
	return;
}
int KMP(int x)
{
	int cnt=0;
	for(int i=0,j=-1;i<lenA;i++)
	{
		while(0<=j&&A[i]!=B[j+1]) j=pre[j];
		if(A[i]==B[j+1])
		{
			j++;
			if(j==x-1)
			{
				cnt++;
				j=pre[j];
			}
		}
	}
	return cnt;
}
int main()
{
	int x,l,mid,r;
	gets(A); lenA=strlen(A);
	gets(B); lenB=strlen(B);
	get_pre();
	scanf("%d",&x);
	r=lenB+1; l=0;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(x<=KMP(mid)) l=mid;
		else r=mid;
	}
	if(l==0) puts("IMPOSSIBLE");
	else for(int i=0;i<l;i++)
		putchar(B[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

