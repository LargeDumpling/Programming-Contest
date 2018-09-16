/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) ((x)&(-x))
using namespace std;
const int MAXN=100050;
int T_T,n,Log[MAXN],num[MAXN],cnt[MAXN];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int calc(int x)
{
	int ans;
	for(ans=0;x!=1;x>>=1) ans++;
	return ans;
}
int main()
{
	int ans,limit;
	Log[0]=-1;
	read1n(T_T);
	while(T_T--)
	{
		ans=limit=0;
		read1n(n);
		for(int i=1;i<=n;i++)
		{
			read1n(num[i]);
			int t=calc(num[i]);
			cnt[t]++;
			limit=max(limit,t);
		}
		for(int i=0;i<=limit;i++)
			ans=max(ans,cnt[i]);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			cnt[calc(num[i])]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

