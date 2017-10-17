/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n,T,next[100050],fir[100050],size[100050],f[100050];
void DFS(int u)
{
	size[u]=0;
	for(int i=fir[u];i!=-1;i=next[i])
	{
		DFS(i);
		size[u]++;
	}
	return;
}
int dp(int u)
{
	if(f[u]!=-1)return f[u];
	if(!size[u])return f[u]=1;
	f[u]=0;
	vector<int>son;
	for(int i=fir[u];i!=-1;i=next[i])
		son.push_back(dp(i));
	/*printf("%d : ",u);
	for(int i=fir[u];i!=-1;i=next[i])
		printf("(%d , %d) ",i,dp(i));
	printf("\t%d",(size[u]*T-1)/100);
	printf("\n");*/
	sort(son.begin(),son.end());
	for(int i=(size[u]*T-1)/100;i>=0;i--)
		f[u]+=son[i];
	return f[u];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int temp;
	while(scanf("%d%d",&n,&T)==2)
	{
		if(n==0&&T==0)break;
		memset(fir,-1,sizeof(fir));
		memset(next,-1,sizeof(next));
		memset(f,-1,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&temp);
			next[i]=fir[temp];
			fir[temp]=i;
		}
		DFS(0);
		printf("%d\n",dp(0));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

