/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bitset>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,m,a[MAXN],ans[MAXN];
bool vis[MAXN];
int gcd(int A,int B)
{
	int t;
	while(B)
	{
		t=A%B;
		A=B;
		B=t;
	}
	return A;
}
int main()
{
	memset(vis,false,sizeof(vis));
	int om;
	scanf("%d%d",&n,&m);
	om=m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		m=gcd(a[i],m);
	}
	for(int j=0;j<om;j+=m)
		vis[j]=true;
	ans[0]=0;
	for(int i=0;i<om;i++) if(vis[i])
		ans[++ans[0]]=i;
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

