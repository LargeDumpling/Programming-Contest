/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,A[405],B[405],an,link[405];
bool f[405][405],exist[405];
map<string,int>IDs;
int get_ID(string X)
{
	if(!IDs.count(X))return IDs[X]=IDs.size();
	return IDs[X];
}
bool fInd(int x)
{
	for(int i=1;i<=m;i++)if(f[A[x]][B[i]]&&!exist[i])
	{
		exist[i]=true;
		if(!link[i]||fInd(link[i]))
		{
			link[i]=x;
			return true;
		}
	}
	return false;
}
int hungary()
{
	memset(link,0,sizeof link);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memset(exist,false,sizeof(exist));
		if(fInd(i))
			ans++;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T;
	string texa,texb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&m);
		memset(f,false,sizeof(f));
		IDs.clear();
		for(int i=1;i<=m;i++)
		{
			cin>>texa;
			B[i]=get_ID(texa);
		}
		scanf("%d",&n);for(int i=1;i<=n;i++)
		{
			cin>>texb;
			cin>>texa;
			A[i]=get_ID(texa);
			f[A[i]][A[i]]=true;
		}
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			cin>>texa>>texb;
			f[get_ID(texa)][get_ID(texb)]=true;
		}
		an=IDs.size();
		for(int k=1;k<=an;k++)
			for(int i=1;i<=an;i++)
				for(int j=1;j<=an;j++)if(k!=i&&k!=j&&i!=j)
					f[i][j]=f[i][j]|(f[i][k]&f[k][j]);
		printf("%d\n",n-hungary());
		if(T)putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

