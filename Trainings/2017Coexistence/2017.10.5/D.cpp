#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=105;
struct jp
{
	char str[105];
	int len;
	jp(char *T)
	{
		len=strlen(T);
		memcpy(str,T,sizeof(char)*(len+1));
	}
	jp operator+(const jp &X)const
	{
		jp ans;
		ans.len=min(100,len+X.len);
		for(int i=0;i<ans.len;i++)
			ans.str[i]=i<len?str[i]:X.str[i-len];
		ans.str[ans.len]='\0';
		return ans;
	}
	jp flip()
	{
		jp ans=*this;
		for(int i=0;(i<<1)<len;i++)
			swap(str[i],str[len-1-i]);
		return ans;
	}
}he[MAXN],en[MAXN];
int n,m,len[MAXN];
char str[MAXN][105];
int main()
{
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<=len;i++)
	{
		scanf("%s",str[i]);
		len[i]=strlen(str[i]);
		he[i]=jp(str);
		for(k[i]=0;check(k[i]+1);k[i]++);
	}
	scanf("%d",&m);
	for(int i=n+1;i<=n+m;i++)
	{
		scanf("%d%d",&u,&v);
		he[i]=he[u]+he[v];
		en[i]=
	}
