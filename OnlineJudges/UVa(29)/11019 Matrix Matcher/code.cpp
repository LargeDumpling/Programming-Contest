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
int n,m,x,y;
int repr[105],next[105],cnt[1050][1050];
int ch[260060][26],sz,pre[260050],word[260060];//,last[260050];
char T[1050][1050],tex[105][105];
void insert(char *tex,int num)
{
	int u;
	for(u=0;*tex!='\0';u=ch[u][*(tex++)-97])
		if(!ch[u][*tex-97])
		{
			ch[u][*tex-97]=++sz;
			memset(ch[sz],0,sizeof(ch[sz]));
			word[sz]=0;
		}
	word[u]=num;
	return;
}
/*int q[10000050];
int inc(int &x){return ++x?x-10000048:x;}
#define head q[0]
#define tail q[10000049]*/
void get_fail()
{
	//memset(q,head=tail=0,sizeof(q));
	memset(pre,0,sizeof(pre));
	queue<int>q;
	int u,v,f;
	for(int i=0;i<26;i++)
		if(ch[0][i]) 
			//q[inc(tail)]=ch[0][i];
		{
			q.push(ch[0][i]);
			//last[ch[0][i]]=0;
		}
	//while(head!=tail)
	while(q.size())
	{
		//u=q[inc(head)];
		u=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(!ch[u][i]) { ch[u][i]=ch[pre[u]][i]; continue; }
			v=ch[u][i];
			//q[inc(tail)]=v;
			q.push(v);
			f=pre[u];
			while(f&&!ch[f][i])f=pre[f];
			pre[v]=ch[f][i];
			//last[v]=word[pre[v]]?pre[v]:last[pre[v]];
		}
	}
	return;
}
/*#undef head
#undef tail*/
void cOunt(int pos,int r,int u)
{
	int c=pos-y+1;
	for(int i=repr[u];i;i=next[i])
		if(r>=i) cnt[r-i+1][c]++;
	return;
}
void report(int pos,int r,int u)
{
	if(u)
	{
		cOunt(pos,r,u);
		//report(pos,r,last[u]);
	}
	return;
}
void fInd(char te[],int r)
{
	int u=0;
	for(int i=0;te[i]!='\0';i++)
	{
		u=ch[u][te[i]-97];
		if(word[u])cOunt(i,r,word[u]);
			//report(i,r,word[u]);
		//else if(last[u])// cOunt(i,r,last[u]);
			//report(i,r,last[u]);
	}
	return;
}
void init()
{
	memset(ch[0],sz=0,sizeof(ch[0]));
	memset(cnt,0,sizeof(cnt));
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("code.out","w",stdout);
	int cAse;
	scanf("%d",&cAse);
	while(cAse--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%s",T[i]);
		scanf("%d%d",&x,&y);
		for(int i=1;i<=x;i++)
		{
			scanf("%s",tex[i]);
			repr[i]=i;
			next[i]=0;
			for(int j=1;j<i;j++)
				if(!strcmp(tex[i],tex[j]))
				{
					repr[i]=j;
					next[i]=next[j];
					next[j]=i;
					break;
				}
			if(repr[i]==i)insert(tex[i],i);
		}
		get_fail();
		for(int i=1;i<=n;i++) fInd(T[i],i);
		int ans=0;
		//cerr<<(n-x)<<" "<<(m-y) << endl;
		for(int i=1;i<=n-x+1;i++) 
			for(int j=0;j<=m-y;j++) 
				if(cnt[i][j]==x) ans++;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

