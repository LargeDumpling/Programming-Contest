/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,C,ans;
char tex[20050][205];
void sUm(int a,int b)
{
	int cnt=0;
	for(int i=0;i<m;i++)
		if(tex[a][i]!=tex[b][i])
			cnt++;
	if(cnt==1)ans++;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	ans=0;
	scanf("%d%d%d",&n,&m,&C);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",tex[i]);
		for(int j=1;j<i;j++)
			sUm(i,j);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

