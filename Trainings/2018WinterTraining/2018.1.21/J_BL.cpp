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
const int mod=30000000;
int n,m,q;
int num[mod],cnt[mod],ans[mod];
void sort()
{
	for(int i=0;i<n;i++)
		cnt[num[i]]++;
	for(int i=1;i<mod;i++)
		cnt[i]+=cnt[i-1];
	for(int i=0;i<n;i++)
		ans[--cnt[num[i]]]=num[i];
	return;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	//freopen("J.in","r",stdin);
	//freopen("J_BL.out","w",stdout);
	int x;
	//scanf("%d%d%d",&n,&m,&q);
	read1n(n);
	read1n(m);
	read1n(q);
	for(int i=0;i<m;i++)
		//scanf("%d",&num[i]);
		read1n(num[i]);
	for(int i=m;i<n;i++)
	{
		num[i]=num[i-m]+num[i-m+1];
		if(mod<num[i])
			num[i]-=mod;
	}
	sort();
	while(q--)
	{
		//scanf("%d",&x);
		read1n(x);
		printf("%d\n",ans[x-1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

