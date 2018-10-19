/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bitset>
#include<algorithm>
using namespace std;
const int MAXN=1024;
int n,m,ans=-1;
bitset<MAXN> ini,sw[MAXN];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void read1n(bitset<MAXN> &A)
{
	int k,x;
	read1n(k);
	for(int i=1;i<=k;i++)
	{
		read1n(x);
		A[x]=1;
	}
	return;
}
int main()
{
	read1n(n); read1n(m);
	read1n(ini);
	sw[0]=0;
	for(int i=1;i<=n&&ans==-1;i++)
	{
		read1n(sw[i]);
		sw[i]^=sw[i-1];
		if(sw[i]==ini)
			ans=i;
	}
	if(ans==-1)
	{
		ini^=sw[n];
		for(int i=1;i<=n&&ans==-1;i++)
			if(sw[i]==ini)
				ans=i;
		if(ans!=-1) ans+=n;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

