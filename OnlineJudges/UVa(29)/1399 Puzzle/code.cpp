/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int ch[50050][26],pre[50050],sz,n,s;
char d[50050];
bool word[50050];
int g[50050],next[50050];
void clear()
{
	memset(ch[0],sz=0,sizeof(ch[0]));
	word[0]=false;
	pre[sz]=0;
	return;
}
void insert(char tex[])
{
	int lenth=strlen(tex),u=0;
	for(int i=0;i<lenth;u=ch[u][tex[i++]-'A'])
		if(!ch[u][tex[i]-'A'])
		{
			ch[u][tex[i]-'A']=++sz;
			memset(ch[sz],0,sizeof(ch[sz]));
			d[sz]=tex[i];
			word[sz]=false;
			pre[sz]=next[sz]=0;
		}
	word[u]=true;
	return;
}
void get_fail()
{
	int u,v,f;
	queue<int>q;
	for(int i=0;i<n;i++) if(ch[0][i]) q.push(ch[0][i]);
	while(q.size())
	{
		u=q.front(); q.pop();
		for(int i=0;i<n;i++)
		{
			if(!ch[u][i])
			{
				ch[u][i]=ch[pre[u]][i];
				continue;
			}
			v=ch[u][i];
			q.push(v);
			f=pre[u];
			while(f&&!ch[f][i]) f=pre[f];
			pre[v]=ch[f][i];
			word[v]|=word[pre[v]];
		}
	}
	return;
}
bool exist[50050],vis[50050];
bool find(int u)
{
	vis[u]=true;
	for(int i=0;i<n;i++)
	{
		int v=ch[u][i];
		if(exist[v]) return true;
		if(word[v]||vis[v]) continue;
		exist[v]=true;
		if(find(v)) return true;
		exist[v]=false;
	}
	return false;
}
int dp(int u)
{
	if(g[u]!=-1) return g[u];
	if(word[u]) return g[u]=0;
	g[u]=next[u]=0;
	int temp,v;
	for(int i=n-1;i>=0;i--)
	{
		v=ch[u][i];
		if(word[v])continue;
		temp=dp(v);
		if(temp+1>g[u])
		{
			g[u]=temp+1;
			next[u]=word[v]?0:v;
		}
	}
	return g[u];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[55];
	int T;
	scanf("%d",&T);
	while(T--)
	{
		clear();
		scanf("%d%d",&n,&s);
		for(int i=1;i<=s;i++)
		{
			scanf("%s",tex);
			insert(tex);
		}
		get_fail();
		memset(exist,false,sizeof(exist));
		memset(vis,false,sizeof(vis));
		exist[0]=true;
		if(find(0)) puts("No");
		else
		{
			memset(g,-1,sizeof(g));
			memset(next,0,sizeof(next));
			if(!dp(0)) puts("No");
			else
			{
				if(!next[0]) puts("No");
				else
				{
					for(int i=next[0];i;i=next[i]) putchar(d[i]);
					putchar('\n');
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

