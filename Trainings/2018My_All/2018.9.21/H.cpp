/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const long long INF=(1LL<<62)-1LL+(1LL<<62);
int n,T_T,num[MAXN],rem[MAXN],c[MAXN],pri[MAXN];
bool exist[MAXN];
long long sum,d[MAXN];
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;i<MAXN;i++)
	{
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<MAXN;j++)
		{
			exist[i*pri[j]]=false;
			if(i%pri[j]==0) break;
		}
	}
	return;
}
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
long long calc(long long x)
{
	if(x==1) return INF;
	long long cnt=INF,preS=0,sufS=0;
	for(int i=1;i<=n;i++)
	{
		rem[i]=num[i]%x;
		sufS+=(x-rem[i]);
	}
	sort(rem+1,rem+n+1);
	if(preS==sufS) cnt=min(cnt,preS);
	for(int i=1;i<=n;i++)
	{
		sufS-=(x-rem[i]);
		preS+=rem[i];
		if(preS==sufS) cnt=min(cnt,preS);
	}
	if(preS==sufS) cnt=min(cnt,preS);
	return cnt;
}
int main()
{
	long long limit,ans;
	pre_calc();
	read1n(T_T);
	while(T_T--)
	{
		sum=d[0]=0;
		read1n(n);
		for(int i=1;i<=n;i++)
		{
			read1n(num[i]);
			sum+=num[i];
		}
		limit=sqrt(sum);
		ans=calc(sum);
		for(int i=1;i<=pri[0]&&pri[i]<=limit;i++) if(sum%pri[i]==0)
		{
			ans=min(ans,calc(pri[i]));
			if(pri[i]!=limit/pri[i])
				ans=min(ans,calc(limit/pri[i]));
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

