/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int a,b,w;
	jp(int A=0,int B=0,int W=0):a(A),b(B),w(W){}
	bool operator<(const jp X)const
	{
		return w<X.w;
	}
}E[6000];
const int D=10000000;
char in[D],*I=in,out[D/10],*O=out;
int n,m,ans,f[105];
bool read1n(int &x)
{
	for(x=0;*I<'0'||'9'<*I;I++)if(*I==-1)return false;
	while('0'<=*I&&*I<='9')x=(x<<1)+(x<<3)+*(I++)-'0';
	return true;
}
void write1n(int x)
{
	if(!x)
	{
		*(O++)='0';
		return;
	}
	if(x<0)
	{
		*(O++)='-';
		x=-x;
	}
	static int s[100];
	for(s[0]=0;x;x/=10)s[++s[0]]=x%10;
	while(s[0])*(O++)=s[s[0]--]+'0';
	return;
}
int fInd(const int &x)
{
	while(f[x]!=f[f[x]])f[x]=f[f[x]];
	return f[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	int tema,cnt,a,b;
	while(read1n(n))
	{
		ans=2147483647;
		read1n(m);
		if(!n&&!m)break;
		for(int i=1;i<=m;i++)
		{
			read1n(E[i].a);
			read1n(E[i].b);
			read1n(E[i].w);
		}
		sort(E+1,E+m+1);
		for(int i=1;i<=m;i++)
		{
			tema=cnt=0;
			for(int j=1;j<=n;j++)f[j]=j;
			for(int j=i;j<=m;j++)
			{
				a=fInd(E[j].a);
				b=fInd(E[j].b);
				if(a!=b)
				{
					f[b]=a;
					cnt++;
					tema=E[j].w;
					if(cnt==n-1)break;
				}
			}
			if(cnt==n-1)
				ans=min(ans,tema-E[i].w);
		}
		if(ans==2147483647)ans=-1;
		write1n(ans);
		*(O++)='\n';
	}
	fwrite(out,1,O-out,stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

