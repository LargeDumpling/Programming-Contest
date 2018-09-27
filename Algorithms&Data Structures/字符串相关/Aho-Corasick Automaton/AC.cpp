#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int MAXC=26;
int ch[MAXN][MAXC],val[MAXN],last[MAXN],pre[MAXN],sz=0;
char tex[MAXN];
void insert(char T[],int x)
{
	int lenth=strlen(T),u=0;
	for(int i=0;i<lenth;u=ch[u][T[i++]-97])
		if(!ch[u][T[i]-97])
			ch[u][T[i]-97]=++sz;
	val[u]=x;
	return;
}
void getfail()
{
	int u,v,f;
	queue<int>q;
	for(int i=0;i<MAXC;i++)
	{
		if(!ch[0][i])
			continue;
		pre[ch[0][i]]=last[ch[0][i]]=0;
		q.push(ch[0][i]);
	}
	while(q.size())
	{
		u=q.front();
		q.pop();
		for(int i=0;i<MAXC;i++)
		{
			if(!ch[u][i])
			{
				ch[u][i]=ch[pre[u]][i];
				continue;
			}
			v=ch[u][i];
			q.push(v);
			f=pre[u];
			while(f&&!ch[f][i])
				f=pre[f];
			pre[v]=ch[f][i];
			last[v]=val[pre[v]]?pre[v]:last[pre[v]];
		}
	}
	return;
}
void count(int u)
{
	if(u)
	{
		// do some operators
		if(last[u]) count(last[u]);
	}
	return;
}
void find(char T[])
{
	int lenth=strlen(T),u=0;
	for(int i=0;i<lenth;i++)
	{
		/*while(u&&!ch[u][T[i]-97])
			u=pre[u];*/
		u=ch[u][T[i]-97];
		if(val[u]) count(u);
		else if(last[u]) count(last[u]);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("AC.out","w",stdout);
	int n,m;
	char temp[MAXN];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",temp);
		insert(temp,i);
	}
	getfail();
	for(int i=1;i<=m;i++)
	{
		scanf("%s",temp);
		if(find(temp))
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

