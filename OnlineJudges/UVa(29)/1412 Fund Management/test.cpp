/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[10],ans=0;
void DFS(int x,int curn)
{
	if(x==9)
	{
		ans++;
		return;
	}
	for(int i=0;i<=8-curn;i++)
	{
		num[x]=i;
		DFS(x+1,curn+i);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	DFS(1,0);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

