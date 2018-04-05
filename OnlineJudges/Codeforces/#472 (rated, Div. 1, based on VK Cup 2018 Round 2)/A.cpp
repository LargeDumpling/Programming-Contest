/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=55;
int n,m,f[105];
char str[MAXN][MAXN];
int fInd(int x)
{
	while(f[x]!=f[f[x]]) f[x]=fInd(f[x]);
	return f[x];
}
void mErge(int u,int v)
{
	u=fInd(u); v=fInd(v);
	f[v]=u;
	return;
}
int main()
{
	bool flag=true;
	for(int i=0;i<100;i++) f[i]=i;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str[i]);
		for(int j=0;j<m;j++) if(str[i][j]=='#')
			mErge(i,n+j);
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++) if(fInd(i)==fInd(j))
			flag&=(strcmp(str[i],str[j])==0);
	if(flag) puts("Yes");
	else puts("No");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

