/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int n,m,Q,pre[MAXN],cnt[MAXN];
char A[MAXN],B[MAXN];
void KMP()
{
	pre[0]=-1;
	for(int i=1,j=-1;i<m;i++)
	{
		while(j!=-1&&B[j+1]!=B[i])
			j=pre[j];
		if(B[j+1]==B[i]) j++;
		pre[i]=j;
	}
	for(int i=0,j=-1;i<n;i++)
	{
		while(j!=-1&&B[j+1]!=A[i])
			j=pre[j];
		if(B[j+1]==A[i])
		{
			j++;
			if(j==m-1)
			{
				j=pre[j];
				cnt[i-m+2]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
		cnt[i]+=cnt[i-1];
	return;
}
int main()
{
	int l,r;
	scanf("%d%d%d",&n,&m,&Q);
	scanf("%s%s",A,B);
	KMP();
	while(Q--)
	{
		scanf("%d%d",&l,&r);
		if(l+m-1<=r) printf("%d\n",cnt[r-m+1]-cnt[l-1]);
		else puts("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

