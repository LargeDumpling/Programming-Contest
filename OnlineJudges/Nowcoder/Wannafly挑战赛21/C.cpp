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
const int MAXN=300050;
int n,a[MAXN],h[MAXN];
long long g[MAXN],f[MAXN],w[MAXN];
bool vis[MAXN];
template<typename Ty>
void read1n(Ty &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
int main()
{
	h[0]=g[0]=f[0]=0;
	memset(vis,false,sizeof(vis));
	read1n(n);
	for(int i=1;i<=n;i++)
	{
		read1n(a[i]);
		h[++h[0]]=a[i];
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(h+1,h+h[0]+1,a[i])-h;
		read1n(g[i]);
		g[i]+=g[i-1];
		f[i]=f[i-1];
		if(vis[a[i]]) f[i]=max(f[i],w[a[i]]+g[i]);
		if(!vis[a[i]])
		{
			w[a[i]]=f[i-1]-g[i-1];
			vis[a[i]]=true;
		}
		else w[a[i]]=max(w[a[i]],f[i-1]-g[i-1]);
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

