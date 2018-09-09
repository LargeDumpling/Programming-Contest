/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2000050;
const int MAXC=10;
const long long mod=1000000007LL;
char str[MAXN];
int ch[MAXN][MAXC],len[MAXN],fail[MAXN],last,sz;
long long num[MAXN],ans,p[MAXN];
int getfail(char T[],int x,int i)
{
	while(T[i-len[x]-1]!=T[i]) x=fail[x];
	return x;
}
void init()
{
	memset(ch[0],last=0,sizeof(ch[0]));//last为当前的最长后缀回文
	memset(ch[1],0,sizeof(ch[1]));
	len[0]=0; len[1]=-1;
	fail[0]=1;
	num[0]=num[1]=0;
	sz=1;
	ans=0;
	return;
}
void insert(char T[])
{
	int lenth=strlen(T),cur=0;
	for(int i=0;i<lenth;i++)
	{
		cur=getfail(T,last,i);
		if(!ch[cur][T[i]-'0'])
		{
			fail[++sz]=ch[ getfail(T,fail[cur],i) ][T[i]-'0'];
			ch[cur][T[i]-'0']=sz;
			memset(ch[sz],0,sizeof(ch[sz]));
			len[sz]=len[cur]+2;
			if(cur==1) num[sz]=T[i]-'0';
			else num[sz]=(num[cur]*10LL%mod+p[len[cur]+1]*(T[i]-'0')%mod+(T[i]-'0'))%mod;
			ans=(ans+num[sz])%mod;
		}
		last=ch[cur][T[i]-'0'];
	}
	return;
}
void pre_calc()
{
	p[0]=1;
	p[1]=10LL;
	for(int i=2;i<MAXN;i++) p[i]=p[i-1]*p[1]%mod;
	return;
}
int main()
{
	init();
	pre_calc();
	scanf("%s",str);
	insert(str);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

