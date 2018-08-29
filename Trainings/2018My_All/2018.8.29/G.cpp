/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cassert>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int mod=1000000007;
int ans[MAXN];
int T_T,n,Q,A[MAXN],L[MAXN],R[MAXN];
int st[50];
inline void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar()) if(ch==-1) break;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
inline void write1n(int x)
{
	st[0]=0;
	if(!x) st[++st[0]]=0;
	for(;x;x/=10)
		st[++st[0]]=x%10;
	while(st[0])
		putchar('0'+st[st[0]--]);
	return;
}
int cnt[MAXN][2];
int main()
{
	int p;
	read1n(T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&Q);
		for(int i=1;i<=n;i++)
			read1n(A[i]);
		for(int i=1;i<=Q;i++)
		{
			read1n(L[i]);
			read1n(R[i]);
			ans[i]=0;
		}
		for(int i=0;i<20;i++)
		{
			cnt[0][0]=cnt[0][1]=p=0;
			for(int j=1;j<=n;j++)
			{
				cnt[j][0]=cnt[j-1][0];
				cnt[j][1]=cnt[j-1][1];
				p^=((A[j]>>i)&1);
				cnt[j][p]++;
			}
			for(int j=1;j<=Q;j++)
				ans[j]=(ans[j]+(1LL<<i)*(cnt[R[j]][0]-cnt[L[j]-1][0]+1)%mod*(cnt[R[j]][1]-cnt[L[j]-1][1])%mod)%mod;
		}
		for(int i=1;i<=Q;i++)
		{
			write1n(ans[i]);
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
