/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,f[10050];
bool vis[10050];
int find(int x)
{
	while(f[x]!=f[f[x]]) f[x]=f[f[x]];
	return f[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,x,y;
	scanf("%d",&n);
	memset(vis,false,sizeof(vis));
	for(int i=0;i<10050;i++) f[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		x=find(a); y=find(b);
		if(x==y) vis[a]=vis[b]=true;
		else
		{
			if(a>b) swap(a,b);
			vis[a]=true;
			f[find(a)]=find(b);
		}
	}
	for(int i=1;i<=10001;i++) if(!vis[i]) { printf("%d",i-1); break; }
	fclose(stdin);
	fclose(stdout);
	return 0;
}

