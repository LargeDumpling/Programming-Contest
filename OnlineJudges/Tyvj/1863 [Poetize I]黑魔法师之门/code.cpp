/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int D=10000000;
const int mod=1000000009;
char in[D],*I=in;
void read1n(int &x)
{
	for(x=0;*I<'0'||'9'<*I;I++);
	while('0'<=*I&&*I<='9') x=(x<<1)+(x<<3)+*(I++)-'0';
	return;
}
int f[200050],n,m,ans=0;
int find(int x)
{
	while(f[x]!=f[f[x]]) f[x]=f[f[x]];
	return f[x];
}
int s[35];
void write1n(int x)
{
	if(!x) puts("0");
	else
	{
		for(s[0]=0;x;x/=10) s[++s[0]]=x%10;
		while(s[0]) putchar(s[s[0]--]+'0');
		putchar('\n');
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	int a,b;
	read1n(n); read1n(m);
	for(int i=1;i<=n;i++) f[i]=i;
	while(m--)
	{
		read1n(a); read1n(b);
		a=find(a); b=find(b);
		if(a!=b) f[a]=b;
		else
		{
			ans=(ans<<1)+1;
			if(ans>=mod) ans-=mod;
		}
		//printf("%d\n",ans);
		write1n(ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

