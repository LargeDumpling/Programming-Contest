/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-06-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=500050;
int ch[MAXN][26],len[MAXN],pre[MAXN],sz;
char str[MAXN];
int get_pre(char *T,int u,int i)
{
	while(i-len[u]-1<0||str[i]!=str[i-len[u]-1])
		u=pre[u];
	return u;
}
void insert(char T[])
{
	int u,cur=1;
	for(int i=0;T[i]!='\0';i++)
	{
		u=get_pre(T,cur,i);
		if(!ch[u][T[i]-'a'])
		{
			sz++;
			memset(ch[sz],0,sizeof(ch[sz]));
			pre[sz]=ch[get_pre(T,pre[u],i)][T[i]-'a'];
			ch[u][T[i]-'a']=sz;
			len[sz]=len[u]+2;
		}
		cur=ch[u][T[i]-'a'];
	}
	return;
}
void init()
{
	memset(ch[0],0,sizeof(ch[0]));
	memset(ch[1],0,sizeof(ch[1]));
	len[0]=0; len[1]=-1;
	pre[0]=1; pre[1]=0;
	sz=1;
	return;
}
int main()
{
	init();
	scanf("%s",str);
	insert(str);
	printf("%d",sz-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

