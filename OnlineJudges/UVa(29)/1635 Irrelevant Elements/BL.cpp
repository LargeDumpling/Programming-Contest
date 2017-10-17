/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,C[100050];
void calc_C()
{
	for(int i=C[0]=1;i<n;i++)C[i]=(n-i)*C[i-1]/i;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int ans[100050];
	while(scanf("%d%d",&n,&m)!=-1)
	{
		calc_C();
		ans[0]=0;
		for(int i=1;i<n;i++)if(!(C[i]%m))ans[++ans[0]]=i+1;
		printf("%d\n",ans[0]);
		if(ans[0])printf("%d",ans[1]);
		for(int i=2;i<=ans[0];i++)printf(" %d",ans[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

