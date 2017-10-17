/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	static const int MAXN=10050;
	int fa[MAXN],son[MAXN][2];
	bool rev[MAXN];
	jp()
	{
		memset(fa,0,sizeof(fa)):
		memset(son,0,sizeof(son)):
		memset(rev,false,sizeof(rev)):
	}
	bool isroot(int x) { return son[fa[x]][0]!=x&&x!=son[fa[x]][1]; }
	void adjust(int r)
	{
		int par=fa[r],avo=fa[fa[r]];
		if(!isroot(par)) son[avo][par==son[avo][1]]=r;
		fa[r]=avo;
		fa[par]=r;
		int d=(r==son[par][1]);
		fa[son[r][d^1]]=par;
		son[par][d]=son[r][d^1];
		son[r][d^1]=par;
		return;
	}
	void down(int x)
	{
		if(!rev[x]) return;
		rev[son[x][0]]^=true;
		rev[son[x][1]]^=true;
		swap(son[x][0],son[x][1]);
		rev[x]=false;
		return;
	}
	void DOWN(int x)
	{
		if(!isroot(x))DOWN(fa[x]);
		down(x);
		return;
	}
	void SPlay(int x)
	{
		int par,avo;
		while(!isroot(x))
		{
			par=fa[x],avo=fa[fa[x]];
			if(!isroot(par))
				if((son[par][1]==x)^(son[avo][1]==par)) adjust(x);
				else adjust(par);
		}
	}
}LCT;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

