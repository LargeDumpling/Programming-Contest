/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[100050],in[100050];
int lenth,len[100050],pre[100050],ch[100050][26],end[100050],sta[100050],sz,last;
int ans;
void init()
{
	memset(ch[0],last=0,sizeof(ch[0]));
	memset(ch[1],0,sizeof(ch[1]));
	memset(pre,0,sizeof(pre));
	memset(len,0,sizeof(len));
	len[0]=0; len[1]=-1; pre[0]=sz=1;
	in[0]='^';
	return;
}
int get_fail(int x,int i) { while(in[i-len[x]-1]!=in[i]) x=pre[x]; return x; }
void build_PT()
{
	int u;
	init();
	for(int i=0;i<lenth;i++)
	{
		in[i]=tex[i];
		u=get_fail(last,i);
		if(!ch[u][in[i]-97])
		{
			memset(ch[++sz],0,sizeof(ch[sz]));
			len[sz]=len[u]+2;
			pre[sz]=ch[get_fail(pre[u],i)][in[i]-97];
			ch[u][in[i]-97]=sz;
		}
		end[i]=len[last=ch[u][in[i]-97]];
	}
	init();
	for(int i=0;i<lenth;i++)
	{
		in[i]=tex[lenth-i-1];
		u=get_fail(last,i);
		if(!ch[u][in[i]-97])
		{
			memset(ch[++sz],0,sizeof(ch[sz]));
			len[sz]=len[u]+2;
			pre[sz]=ch[get_fail(pre[u],i)][in[i]-97];
			ch[u][in[i]-97]=sz;
		}
		sta[lenth-i-1]=len[last=ch[u][in[i]-97]];
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%s",tex);
	lenth=strlen(tex);
	build_PT();
	for(int i=0;i<lenth-1;i++) ans=max(ans,end[i]+sta[i+1]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

