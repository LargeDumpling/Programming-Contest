#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ch[100050][26],len[100050],fail[100050],cnt[100050],last,sz;
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
			ch[cur][T[i]-97]=++sz;
			memset(ch[sz],0,sizeof(ch[sz])); len[sz]=0;
			fail[sz]=ch[ getfail(T,fail[cur],i) ][T[i]-97];
		}
		last=ch[cur][T[i]-97];
		cnt[last]++;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

