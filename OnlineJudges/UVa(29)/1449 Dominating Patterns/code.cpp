/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int lenT,ch[10550][26],sz,n,word[10550],pre[10550],cnt[155],last[10550];
char T[1000050],tex[155][100];
void insert(int x)
{
	int u=0;
	for(int i=0;tex[x][i]!='\0';u=ch[u][tex[x][i++]-97])
		if(!ch[u][tex[x][i]-97])
			ch[u][tex[x][i]-97]=++sz;
	word[u]=x;
	return;
}
void get_fail()
{
	int u,v,f;
	queue<int>q;
	memset(pre,0,sizeof(pre));
	for(int i=0;i<26;i++) if(ch[0][i]) q.push(ch[0][i]);
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
			v=ch[u][i];
			q.push(v);
			f=pre[u];
			while(f&&!ch[f][i])f=pre[f];
			pre[v]=ch[f][i];
			last[v]=word[pre[v]]?pre[v]:last[pre[v]];
		}
	}
	return;
}
void cOunt(int x)
{
	if(!x)return;
	cnt[word[x]]++;
	cOunt(last[x]);
	return;
}
void find()
{
	int u=0;
	lenT=strlen(T);
	for(int i=0;i<lenT;i++)
	{
		if(u&&!ch[u][T[i]-97]) u=pre[u];
		u=ch[u][T[i]-97];
		if(word[u]) cOunt(u);
		else if(last[u]) cOunt(last[u]);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int mAx;
	while(scanf("%d",&n)!=-1&&n)
	{
		memset(ch,sz=0,sizeof(ch));
		memset(word,0,sizeof(word));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex[i]);
			insert(i);
		}
		get_fail();
		scanf("%s",T);
		find();
		mAx=0;
		for(int i=1;i<=n;i++) if(cnt[i]>mAx) mAx=cnt[i];
		printf("%d\n",mAx);
		for(int i=1;i<=n;i++) if(cnt[i]==mAx) printf("%s\n",tex[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

