#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int ch[205][26],sz=0,n,p,k,Len,wn,len[7],F[41][7][205];
char T[205],word[7][205];
bool wo[205];
void insert(char tex[])
{
	int Lenth=strlen(tex),u=0;
	for(int i=0;i<Lenth;u=ch[u][tex[i++]-97])
		if(!ch[u][tex[i]-97])
			ch[u][tex[i]-97]=++sz;
	wo[u]=true;
	return;
}
bool query(char tex[])
{
	int Lenth=strlen(tex),u=0;
	for(int i=0;i<Lenth;u=ch[u][tex[i++]-97])
		if(!ch[u][tex[i]-97])
			return false;
	if(wo[u])
		return true;
	return false;
}
bool query(int pos,int x)
{
	int i;
	for(i=0;i<len[x]&&T[i+pos]==word[x][i];i++);
	if(i==len[x])
		return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&p,&k);
		Len=p*20;
		for(int i=0;i<p;i++)
			scanf("%s",tex+i*20);
		scanf("%d",&wn);
		for(int i=1;i<=wn;i++)
		{
			scanf("%s",word[i]);
			len[i]=strlen(word[i]);
		}
		for(int i=0;i<=k;i++)
		{
			for(int j=1;j<=wn;j++)
			{
				for(int k=Len;k>=len[j];k--)
				{
					if(query(k-len[j],j))
						F[i][j][k]=max(F[i][j][k],F[i][j-1][k-len[j]]);
				}
			}
		}
	}
	return 0;
}

