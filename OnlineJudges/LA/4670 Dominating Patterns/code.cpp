#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
int ch[100050][26],val[100050],last[100050],pre[100050],cnt[155],sz=0,n;
char tex[1000050];
void insert(char T[],int x)
{
	int lenth=strlen(T),u=0;
	for(int i=0;i<lenth;u=ch[u][T[i++]-97])
		if(!ch[u][T[i]-97])
		{
			ch[u][T[i]-97]=++sz;
			memset(ch[sz],val[sz]=last[sz]=pre[sz]=0,sizeof(ch[sz]));
		}
	val[u]=x;
	return;
}
void getfail()
{
	int u,v,f;
	queue<int>q;
	for(int i=0;i<26;i++)
		if(ch[0][i])
		{
			pre[ch[0][i]]=last[ch[0][i]]=0;
			q.push(ch[0][i]);
		}
	while(q.size())
	{
		u=q.front();
		q.pop();
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
			while(f&&!ch[f][i])
				f=pre[f];
			pre[v]=ch[f][i];
			last[v]=val[pre[v]]?pre[v]:last[pre[v]];
		}
	}
	return;
}
void find()
{
	int lenth=strlen(tex),u=0;
	for(int i=0;i<lenth;i++)
	{
		u=ch[u][tex[i]-97];
		if(val[u])
			cnt[val[u]]++;
		else if(last[u])
			cnt[last[u]]++;
	}
	return;
}
/*The entire input contains multi cases.The first line of each case is an integer,
which is the number of patterns N, 1<=N<=150. Each of the following N lines contains one
pattern, whose length is in range [1, 70]. The rest of the case is one line contains a large
string as the text to lookup, whose length is up to 106.
At the end of the input file, number `0' indicates the end of input file.*/
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int maxn=-2147483647;
	char temp[155][75];
	while(true)
	{
		scanf("%d",&n);
		if(!n)
			break;
		memset(ch[0],0,sizeof(ch[0]));
		memset(cnt,0,sizeof(cnt));
		sz=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",temp[i]);
			insert(temp[i],i);
		}
		scanf("%s",tex);
		getfail();
		find();
		maxn=0;
		cnt[0]=-2147483647;
		for(int i=1;i<=n;i++)
			if(cnt[i]>cnt[maxn])
				maxn=i;
		printf("%d\n",cnt[maxn]);
		for(int i=1;i<=n;i++)
			if(cnt[i]==cnt[maxn])
				printf("%s\n",temp[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

