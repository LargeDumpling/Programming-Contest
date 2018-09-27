#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int MAXC=26;
int ch[MAXN][MAXC],len[MAXN],fail[MAXN],cnt[MAXN],last,sz;
int getfail(char T[],int x,int i)
{
	while(T[i-len[x]-1]!=T[i]) x=fail[x];
	return x;
}
void init()
{
	memset(ch[0],last=0,sizeof(ch[0]));//last为当前的最长后缀回文
	memset(ch[1],0,sizeof(ch[1]));
	len[0]=0; len[1]=-1; fail[0]=1;
	sz=1;
	return;
}
void insert(char T[])
{
	int lenth=strlen(T),cur;
	for(int i=0;i<lenth;i++)
	{
		cur=getfail(T,last,i);
		if(!ch[cur][T[i]-97])
		{
			fail[++sz]=ch[getfail(T,fail[cur],i)][T[i]-97];
			ch[cur][T[i]-97]=sz;
			memset(ch[sz],0,sizeof(ch[sz]));
			len[sz]=len[cur]+2;
		}
		last=ch[cur][T[i]-97];
		cnt[last]++;
	}
}
int main()
{
	fclose(stdin);
	fclose(stdout);
	return 0;
}

