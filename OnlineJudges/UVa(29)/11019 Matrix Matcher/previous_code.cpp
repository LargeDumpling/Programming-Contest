#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int ch[10050][26],val[10050],pre[10050],last[10050],nexta[10050],cnt[1050][1050],sz=0,Tn,Tm,n,m,ans;
char T[1050][1050];
void insert(char tex[],int x)
{
	int lenth=strlen(tex),u=0;
	for(int i=0;i<lenth;u=ch[u][tex[i++]-97])
		if(!ch[u][tex[i]-97])
		{
			ch[u][tex[i]-97]=++sz;
			memset(ch[sz],val[sz]=pre[sz]=last[sz]=0,sizeof(ch[sz]));
		}
	if(val[u])
	{
		nexta[x]=val[u];
		val[u]=x;
	}
	else
		val[u]=x;
	return;
}
void getfail()
{
	int u,v,f;
	queue<int>q;
	for(int i=0;i<=25;i++)
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
		for(int i=0;i<=25;i++)
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
			last[v]=val[pre[v]]?val[pre[v]]:last[pre[v]];
		}
	}
	return;
}
void find(int i)
{
	int u=0,temp=0;
	for(int j=0;j<Tm;j++)
	{
		temp=0;
		u=ch[u][T[i][j]-97];
		if(val[u])
			temp=val[u];
		else if(last[u])
			temp=last[u];
		for(;temp;temp=nexta[temp])
		{
			cnt[i-temp+1][j]++;
			if(cnt[i-temp+1][j]==n)
				ans++;
		}
		/*if(val[u])
		{
			cnt[i-val[u]+1][j]++;
			if(cnt[i-val[u]+1][j]==n)
				ans++;
		}
		else if(last[u])
		{
			cnt[i-last[u]+1][j]++;
			if(cnt[i-last[u]+1][j]==n)
				ans++;
		}*/
	}
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("code.txt","w",stdout);
	int cas;
	char tex[105][105];
	scanf("%d",&cas);
	while(cas--)
	{
		memset(ch[0],sz=ans=0,sizeof(ch[0]));
		memset(cnt,0,sizeof(cnt));
		memset(val,0,sizeof(val));
		memset(nexta,0,sizeof(nexta));
		scanf("%d%d",&Tn,&Tm);
		for(int i=0;i<Tn;i++)
			scanf("%s",T[i]);
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%s",tex[i]);
			insert(tex[i],i+1);
		}
		getfail();
		for(int i=0;i<Tn;i++)
			find(i);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

