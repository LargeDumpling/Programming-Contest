/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
bool vis[MAXN];
void Eratosthenes()
{
	int m=sqrt(n+0.5);
	memset(vis,false,sizeof(vis));
	for(int i=2;i<=m;i++) if(!vis[i])
		for(int j=i*i;j<=n;j+=i) vis[j]=true;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

