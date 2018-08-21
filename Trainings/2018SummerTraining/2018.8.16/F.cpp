/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int ch[MAXN][26],val[MAXN],pre[MAXN],last[MAXN],dis[MAXN],sz=0;
int st[MAXN];
char str[MAXN];
bool vis[MAXN];
void insert(char T[],int x)
{
	int u=0;
	st[0]=0;
	for(int i=0;T[i]!='\0';u=ch[u][T[i++]-'a'])
	{
		st[++st[0]]=u;
		if(!ch[u][T[i]-'a'])
		{
			ch[u][T[i]-'a']=++sz;
			memset(ch[sz],0,sizeof(ch[sz]));
			val[sz]=pre[sz]=last[sz]=0;
		}
	}
	st[st[0]+1]=u;
	val[u]=x;
	dis[u]=0;
	for(int i=st[0];i;i--)
		dis[st[i]]=min(dis[st[i]],dis[st[i+1]]+1);
	return;
}
queue<int> q;
void get_fail()
{
	int u=0,f,v;
	for(int i=0;i<26;i++) if(ch[u][i])
	{
		v=ch[u][i];
		pre[v]=last[v]=0;
		dis[v]=min(dis[v],dis[u]);
		q.push(v);
	}
	while(q.size())
	{
		u=q.front(); q.pop();
		for(int i=0;i<26;i++)
		{
			if(!ch[u][i])
			{
				ch[u][i]=ch[pre[u]][i];
				continue;
			}
			else
			{
				v=ch[u][i];
				for(f=pre[u];f&&!ch[f][i];f=pre[f]);
				pre[v]=ch[f][i];
				dis[v]=min(dis[v],dis[pre[v]]);
				last[v]=val[pre[v]]?pre[v]:last[pre[v]];
				q.push(v);
			}
		}
	}
	return;
}
int main()
{
	int n;
	memset(dis,127,sizeof(dis));
	memset(vis,false,sizeof(vis));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		insert(str,i);
	}
	get_fail();
	scanf("%s",str+1);
	st[0]=0;
	printf("%d\n",dis[0]);
	for(int i=1;str[i]!='\0';i++)
	{
		if(str[i]=='-')
		{
			if(st[0])
				st[0]--;
		}
		else
		{
			st[st[0]+1]=ch[st[st[0]]][str[i]-'a'];
			st[0]++;
		}
		printf("%d\n",dis[st[st[0]]]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

