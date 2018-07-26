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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=gcd(a[i],m);
	}
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) vis[0]=true;
		else for(int j=0;j<m;j+=a[i])
			vis[j]=true;
	}
	ans[0]=0;
	for(int i=0;i<m;i++) if(vis[i])
		ans[++ans[0]]=i;
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

