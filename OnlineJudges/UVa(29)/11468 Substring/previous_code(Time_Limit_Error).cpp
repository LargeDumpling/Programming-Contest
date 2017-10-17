#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int ch[405][62],pre[405],sz=0;
double prob[62],f[405][105];
bool word[405];
int idx(char c)
{
	if('0'<=c&&c<='9')
		return c-48;
	else if('A'<=c&&c<='Z')
		return c-55;
	else if('a'<=c&&c<='z')
		return c-61;
}
void insert(char T[])
{
	int lenth=strlen(T),u=0;
	for(int i=0;i<lenth;u=ch[u][idx(T[i++])])
		if(!ch[u][idx(T[i])])
		{
			ch[u][idx(T[i])]=++sz;
			memset(ch[sz],pre[sz]=0,sizeof(ch[sz]));
			word[sz]=false;
		}
	word[u]=true;
	return;
}
void getfail()
{
	int u,v,f;
	queue<int>q;
	for(int i=0;i<62;i++)
		if(ch[0][i])
		{
			pre[ch[0][i]]=0;
			q.push(ch[0][i]);
		}
	while(q.size())
	{
		u=q.front();
		q.pop();
		for(int i=0;i<62;i++)
		{
			if(!ch[u][i])
			{
				ch[u][i]=ch[pre[u]][i];
				continue;
			}
			v=ch[u][i];
			f=pre[u];
			while(f&&!ch[f][i])
				f=pre[f];
			pre[v]=ch[f][i];
			if(!word[v])
				word[v]=word[pre[v]];
			q.push(v);
		}
	}
	return;
}
double getans(int u,int L)
{
	if(!L)
		return 1;
	if(!f[u][L])
	{
		double &ans=f[u][L]=0;
		for(int i=0;i<62;i++)
			if(!word[ch[u][i]])
				ans+=prob[i]*getans(ch[u][i],L-1);
	}
	return f[u][L];
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("code.txt","w",stdout);
	int cas,temp,L;
	char tex[25];
	scanf("%d\n",&cas);
	for(int k=1;k<=cas;k++)
	{
		memset(ch[0],sz=0,sizeof(ch[0]));
		memset(f,0,sizeof(f));
		memset(prob,0,sizeof(prob));
		memset(word,false,sizeof(word));
		scanf("%d",&temp);
		for(int i=1;i<=temp;i++)
		{
			scanf("%s",tex);
			insert(tex);
		}
		scanf("%d",&temp);
		getfail();
		while(temp--)
		{
			scanf("%s",&tex[0]);
			scanf("%lf",&prob[idx(tex[0])]);
		}
		scanf("%d",&L);
		printf("Case #%d: %.6lf\n",k,getans(0,L));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

