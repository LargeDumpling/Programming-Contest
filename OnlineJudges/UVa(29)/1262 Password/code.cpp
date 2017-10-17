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
int h[6][7],T,k,cnt=0,d[7];
bool exist[6][26];
char ans[7];
bool k_th(int cur,int rank)
{
	if(cur==5&&rank==1)
	{
		ans[6]='\0';
		printf("%s\n",ans+1);
		return true;
	}
	if(rank>d[cur+1])return false;
	int t=(rank-1)/d[cur+2]+1,nrank;
	ans[cur+1]=h[cur+1][t]+'A';
	nrank=(rank==t*d[cur+2])?d[cur+2]:rank-(t-1)*d[cur+2];
	return k_th(cur+1,nrank);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
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
		d[6]=1;
		for(int i=5;i;i--)d[i]=d[i+1]*h[i][0];
		if(!k_th(0,k))printf("NO\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

