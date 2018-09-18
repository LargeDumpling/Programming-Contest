/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int n,h,x[MAXN][2],len[MAXN];
int main()
{
	int l,r,ans=0;
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i][0],&x[i][1]);
		len[i]=len[i-1]+x[i][1]-x[i][0];
	}
	for(l=r=1;l<=n;l++)
	{
		while(r<n&&(x[r+1][0]-x[l][0]-len[r]+len[l-1])<h) r++;
		if((x[r][1]-x[l][0]-len[r]+len[l-1])<h)
			ans=max(ans,h+len[r]-len[l-1]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

