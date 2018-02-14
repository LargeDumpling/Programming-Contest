/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-02	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
int n,k,num[205];
int main()
{
	int ans;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&k);
		num[0]=ans=0;
		for(int i=1;i<=k;i++)
			scanf("%d",&num[i]);
		num[0]=-num[1]+1;
		num[k+1]=n+(n-num[k])+1;
		for(int i=k+1;i;i--)
			ans=max(ans,(num[i]-num[i-1])/2+1);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

