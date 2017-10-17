/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int nl,nr,m,rIght[550],exist[550];
vector<int> lEft[550];
bool fInd(int u,int cur)
{
	int v;
	for(unsigned i=0;i<lEft[u].size();i++)
	{
		v=lEft[u][i];
		if(exist[v]==cur) continue;
		exist[v]=cur;
		if(!rIght[v]||fInd(rIght[v],cur))
		{
			rIght[v]=u;
			return true;
		}
	}
	return false;
}
int hungary()
{
	int ans=0;
	for(int i=1;i<=nr;i++)
		if(fInd(i,i))
			ans++;
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d%d%d",&nl,&nr,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		lEft[b].push_back(a);
	}
	printf("%d\n",hungary());
	for(int i=1;i<=nl;i++) printf("%d ",rIght[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

