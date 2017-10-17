/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int>s;
vector<int>pos[100050];
int get_ID(int x)
{
	if(!s.count(x))return s[x]=s.size();
	return s[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,m,a,b;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		s.clear();
		for(int i=1;i<=100000;i++)pos[i].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			b=get_ID(a);
			pos[b].push_back(i);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			b=get_ID(b);
			if(a<1||a>(int)pos[b].size())puts("0");
			else printf("%d\n",pos[b][a-1]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

