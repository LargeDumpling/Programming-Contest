/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=8000050;
int T_T,n;
int fir[MAXN],next[MAXN],val[MAXN],sz=0;
char data[MAXN];
void insert(char *T,int x)
{
	int u,v;
	for(u=0;*T!='\0';u=v,T++)
	{
		if(!fir[u])
		{
			data[++sz]=*T;
			v=fir[u]=sz;
			continue;
		}
		for(v=fir[u];next[v]&&data[v]!=*T;v=next[v]);
		if(!next[v]&&data[v]!=*T)
		{
			data[++sz]=*T;
			v=next[v]=sz;
		}
	}
	val[u]=x;
	return;
}
int query(char *T)
{
	int u,v;
	for(u=0;*T!='\0';u=v,T++)
		for(v=fir[u];data[v]!=*T;v=next[v]);
	return val[u];
}
void init()
{
	memset(fir,0,sizeof(fir));
	memset(next,0,sizeof(next));
	memset(val,0,sizeof(val));
	memset(data,0,sizeof(data));
	sz=0;
}
int main()
{
	int cnt,r;
	char str[10];
	scanf("%d",&T_T);
	while(T_T--)
	{
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			insert(str,i);
		}
		r=cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			cnt++;
			r=max(r,query(str));
			if(r==i)
			{
				printf("%d ",cnt);
				cnt=0;
			}
		}
		if(cnt) printf("%d",cnt);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

