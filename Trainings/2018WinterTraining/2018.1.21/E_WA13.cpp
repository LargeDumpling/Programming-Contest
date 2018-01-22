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
		if(B[i]==B[j+1]) j++;
		pre[i]=j;
	}
	for(int i=0,j=-1;i<lenA;i++)
	{
		while(0<=j&&A[i]!=B[j+1]) j=pre[j];
		if(A[i]==B[j+1])
			j++;
		mat[i]=j;
		if(j==lenB-1)
			j=pre[j];
	}
	for(int i=0;i<lenA;i++)
		if(mat[i]!=-1)
			cnt[mat[i]]++;
	for(int i=lenB-2;0<=i;i--)
		cnt[i]+=cnt[i+1];
	return;
}
int main()
{
	int x,ans=-1;
	gets(A); lenA=strlen(A);
	gets(B); lenB=strlen(B);
	get_pre();
	scanf("%d",&x);
	for(int i=0;i<lenB;i++)
		if(x<=cnt[i])
			ans=i;
	if(ans==-1) puts("IMPOSSIBLE");
	else for(int i=0;i<=ans;i++)
		putchar(B[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

