/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
bool exist[MAXN],vis[10000050];
int num[MAXN],n;
int main()
{
	memset(exist,false,sizeof(exist));
	memset(vis,false,sizeof(vis));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	for(int i=n;i;i--)
	{
		exist[i]=true;
		for(int j=num[i];j<=10000000;j+=num[i])
		{
			if(vis[j])
			{
				exist[i]=false;
				break;
			}
		}
		if(exist[i]) vis[num[i]]=true;
	}
	for(int i=1;i<=n;i++) if(exist[i])
		printf("%d ",num[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

