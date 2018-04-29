/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool vis[15];
int num[15],ans;
int calc(int x)
{
	memset(vis,false,sizeof(vis));
	int cnt=0,sum=0;
	for(int i=1;i<x;i++)
	{
		if(!vis[num[i]]) vis[num[i]]=true,sum++;
		if(!vis[num[i]+1]) vis[num[i]+1]=true,sum++;
		cnt++;
		if(sum==x) break;
	}
	return cnt;
}
int main()
{
	for(int i=1;i<15;i++) num[i]=i;
	for(int i=2;i<=10;i++)
	{
		ans=0;
		sort(num+1,num+11);
		do
		{
			ans+=calc(i);
		}while(next_permutation(num+1,num+i));
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

