#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int fir[9],end[90],next[90],ed=0,ans[10],num[10],map[10],fmap[10],pn,w[10];
bool exist[9];
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
char tex[105];
int lenth=0;
void DFS(int cur,int curn)
{
	if(cur==pn+1)
	{
		for(int i=1;i<=8;i++)ans[i]=num[i];
		ans[9]=curn;
		return;
	}
	int cnt;
	for(int i=1;i<=8;i++)if(!exist[i])
	{
		cnt=0;
		for(int j=fir[i];j;j=next[j])
		{
			if(!exist[end[j]])
			{
				cnt++;
				continue;
			}
			else if(cur-w[end[j]]>=ans[9])
				return;
			curn=max(curn,cur-w[end[i]]);
		}
		if(cur+cnt>=ans[9])return;
		memset(exist,false,sizeof exist );
		exist[i]=true;
		num[cur]=i;
		w[i]=cur;
		DFS(cur+1,curn);
		exist[i]=false;
	}
	return;
}
bool input()
{
	gets(tex);
	if(tex[0]=='#')return false;
	memset(fir,ed=0,sizeof fir);
	memset(exist,false,sizeof exist);
	lenth=strlen(tex);
	ans[9]=2147483647;
	int u;
	for(int i=map[9]=pn=0;i<lenth;i++)if('A'<=tex[i]&&tex[i]<='Z'&&!exist[tex[i]-'A'])
	{
		map[tex[i]-'A']=++map[9];
		fmap[map[map[9]]]=tex[i]-'A';
		exist[tex[i]-'A']=false;
		pn++;
	}
	memset(exist,false,sizeof exist );
	for(int i=0;i<lenth;i++)
	{
		u=map[tex[i++]-'A'];i++;
		while('A'<=tex[i]&&tex[i]<='Z')addedge(u,map[tex[i]-'A']);
	}
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(input())
	{
		ans[9]=2147483647;
		DFS(1,2147483647);
		for(int i=1;i<=pn;i++)
			printf("%c ",fmap[ans[i]]+'A');
		printf("-> %d\n",ans[9]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

