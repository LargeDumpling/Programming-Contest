/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char T[300050],tex[4050][105];
int lenT,n,lentex[4050],ch[400050][26],sz=0,word[400050],f[300050];
void insert(int x)
{
	int u=0;
	for(int i=0;i<lentex[x];u=ch[u][tex[x][i++]-97])
		if(!ch[u][tex[x][i]-97])
		{
			ch[u][tex[x][i]-97]=++sz;
			memset(ch[sz],0,sizeof(ch[sz]));
		}
	word[u]=x;
	return;
}
void query(int sta)
{
	int u=0;
	for(int i=sta;i<lenT;u=ch[u][T[i++]-97])
	{
		if(!ch[u][T[i]-97])
			break;
		if(word[u])
			f[sta]=(f[sta]+f[sta+lentex[word[u]]])%20071027;
	}
	if(word[u])
		f[sta]=(f[sta]+f[sta+lentex[word[u]]])%20071027;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int cAse;
	for(cAse=1;scanf("%s",T)!=-1;cAse++)
	{
		memset(ch[0],sz=0,sizeof(ch[0]));
		memset(f,0,sizeof(f));
		memset(word,0,sizeof(word));
		lenT=strlen(T);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex[i]);
			lentex[i]=strlen(tex[i]);
			insert(i);
		}
		f[lenT]=1;
		for(int i=lenT-1;i>=0;i--)
			query(i);
		printf("Case %d: %d\n",cAse,f[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

