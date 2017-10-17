/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,belong[30],s[30],dfn[30],low[30],sccn,dfs_clock;
bool call[30][30],f[30][30],printed[30];
map<string,int>ppn;
map<int,string>fppn;
int get_ID(string X)
{
	if(!ppn.count(X))fppn[ppn[X]=ppn.size()]=X;
	return ppn[X];
}
void print(int u)
{
	if(printed[u])return;
	printed[u]=true;
	cout<<fppn[u];
	for(int i=1;i<=n;i++)if(!printed[i])
	{
		if(!f[u][i])continue;
		cout<<", ";
		print(i);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	string A,B;
	for(int cAse=1;scanf("%d%d",&n,&m)!=-1&&(n||m);cAse++)
	{
		if(cAse!=1)putchar('\n');
		printf("Calling circles for data set %d:\n",cAse);
		memset(call,false,sizeof(call));
		memset(f,false,sizeof(f));
		memset(belong,sccn=0,sizeof(belong));
		memset(printed,false,sizeof(printed));
		ppn.clear();fppn.clear();
		for(int i=1;i<=m;i++)
		{
			cin>>A>>B;
			call[a=get_ID(A)][b=get_ID(B)]=true;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)if(k!=i&&k!=j&&i!=j)
					call[i][j]=call[i][j]|(call[i][k]&call[k][j]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				f[i][j]=f[j][i]=(call[i][j]&call[j][i]);
		for(int i=1;i<=n;i++)if(!printed[i])
		{
			print(i);
			putchar('\n');
		}
		//putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

