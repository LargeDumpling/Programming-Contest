/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,ch[2000][26],sz=0,name_n=0;
int val[2000],max_vis=0,ans=0;
int vis[50];
int fInd(char *T)
{
	int u;
	for(u=0;*T!='\0';u=ch[u][*(T++)-'a'])
		if(!ch[u][*T-'a'])
		{
			memset(ch[++sz],0,84);
			val[sz]=0;
			ch[u][*T-'a']=sz;
		}
	if(!val[u]) val[u]=++name_n;
	return val[u];
}
int main()
{
	int opt,idx;
	char str[50];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				ans+=max_vis;
				max_vis=0;
				memset(vis,0,sizeof(vis));
				break;
			case 2:
				scanf("%s",str);
				vis[idx=fInd(str)]++;
				if(max_vis<vis[idx])
					max_vis=vis[idx];
				break;
			default:
				break;
		}
	}
	ans+=max_vis;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

