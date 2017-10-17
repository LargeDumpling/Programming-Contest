/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ch[10000050][2],sz,num[10000050],dis[10000050],T,n;
long long ans=0;
char tex[205];
void insert()
{
	int lenth=strlen(tex),u,v;
	for(int i=0;i<lenth;i++)
	{
		if(!ch[u][tex[i]-'0'])
		{
			ch[u][tex[i]-'0']=++sz;
			memset(ch[sz],0,sizeof(ch[sz]));
			num[sz]=0;
			dis[sz]=dis[u]+1;
		}
		v=ch[u][tex[i]-'0'];
		num[v]++;
		ans=max(ans,(long long)dis[v]*num[v]);
		u=v;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(ch[0],0,sizeof(ch[0]));
		sz=num[0]=dis[0]=ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex);
			insert();
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

