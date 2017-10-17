/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int h[6][7],T,k,cnt=0;
bool exist[6][26];
char ans[7];
bool DFS(int cur)
{
	if(cur==5)
	{
		if(++cnt==k)
		{
			ans[6]='\0';
			printf("%s\n",ans+1);
			return true;
		}
		return false;
	}
	bool flag=false;
	for(int i=1;i<=h[cur+1][0]&&!flag;i++)
	{
		ans[cur+1]=h[cur+1][i]+'A';
		flag|=DFS(cur+1);
	}
	return flag;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	char tex[7];
	scanf("%d",&T);
	while(T--)
	{
		memset(exist,false,sizeof(exist));
		cnt=0;
		scanf("%d",&k);
		for(int i=1;i<=5;i++)h[i][0]=0;
		for(int i=1;i<=6;i++)
		{
			scanf("%s",tex+1);
			for(int j=1;j<=5;j++)exist[j][tex[j]-'A']=true;
		}
		for(int i=1;i<=6;i++)
		{
			scanf("%s",tex+1);
			for(int j=1;j<=5;j++)if(exist[j][tex[j]-'A'])h[j][++h[j][0]]=tex[j]-'A';
		}
		for(int i=1;i<=5;i++)
		{
			sort(h[i]+1,h[i]+h[i][0]+1);
			h[i][0]=unique(h[i]+1,h[i]+h[i][0]+1)-h[i]-1;
		}
		if(!DFS(0))printf("NO\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

