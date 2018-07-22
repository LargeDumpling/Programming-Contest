/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const long long INF=2147483648LL;
int T_T,n;
long long a[MAXN],f[MAXN][2],g[MAXN][2];
template<typename Ty>
void read1n(Ty &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	read1n(T_T);
	while(T_T-->0)
	{
		read1n(n);
		g[0][0]=0;
		f[0][0]=0;
		f[0][0]=0;
		f[0][1]=-INF;
		for(int i=1;i<=n;i++)
		{
			f[i][0]=0;
			f[i][1]=-INF;
			g[i][0]=g[i][1]=INF;
			read1n(a[i]);
			if(f[i-1][0]<f[i-1][1]+a[i])
			{
				f[i][0]=f[i-1][1]+a[i];
				g[i][0]=g[i-1][1]+1;
			}
			else
			{
				f[i][0]=f[i-1][0];
				g[i][0]=g[i-1][0];
			}
			if(f[i-1][1]<f[i-1][0]-a[i])
			{
				f[i][1]=f[i-1][0]-a[i];
				g[i][1]=g[i-1][0]+1;
			}
			else
			{
				f[i][1]=f[i-1][1];
				g[i][1]=g[i-1][1];
			}
		}
		printf("%lld %lld\n",f[n][0],g[n][0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

