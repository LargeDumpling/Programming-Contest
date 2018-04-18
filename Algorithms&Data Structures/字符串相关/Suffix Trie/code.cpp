/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-18	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXL=3050;
const int MAXZ=26;
int ch[MAXL*MAXL][MAXZ],sz,val[MAXL*MAXL],sa[MAXL];
void insert(char *T,int x)
{
	int u;
	for(u=0;*T!='\0';u=ch[u][*(T++)-'a'])
		if(!ch[u][*T-'a'])
			ch[u][*T-'a']=++sz;
	val[u]=x;
	return;
}
void init()
{
	memset(ch,sz=0,sizeof(ch));
	memset(val,0,sizeof(val));
	return;
}
void calc_sa()
{
	int num=0,u;
	queue<int> q;
	q.push(0);
	while(q.size())
	{
		u=q.front(); q.pop();
		if(val[u]) sa[++num]=val[u];
		for(int i=0;i<MAXZ;i++) if(ch[u][i])
			q.push(ch[u][i]);
	}
	return;
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	init();
	int len;
	char str[MAXL];
	scanf("%s",str);
	len=strlen(str);
	for(int i=0;i<len;i++)
		insert(str+i,i);
	calc_sa();
	for(int i=0;i<len;i++)
		printf("%d ",sa[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
