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
int num[2][105],cnt[30000050];
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
	freopen("J.in","r",stdin);
	freopen("J.out","w",stdout);
	int now=0,x;
	read1n(n);
	read1n(m);
	read1n(q);
	for(int i=0;i<m;i++)
	{
		read1n(num[now][i]);
		cnt[num[now][i]]++;
	}
	for(int i=m;i<n;i++)
	{
		if(!(i%m)) now^=1;
		if(i%m!=m-1) num[now][i%m]=(num[now^1][i%m]+num[now^1][i%m+1])%mod;
		else num[now][m-1]=(num[now^1][m-1]+num[now][0])%mod;
		cnt[num[now][i%m]]++;
	}
	for(int i=0;i<mod;i++)
		cnt[i]+=cnt[i-1];
	while(q--)
	{
		read1n(x);
		printf("%d\n",lower_bound(cnt,cnt+mod,x)-cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

