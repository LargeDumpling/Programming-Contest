/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,h[105],ave,ans;
	for(int cAse=1;scanf("%d",&n)!=-1&&n;cAse++)
	{
		ave=ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&h[i]);
			ave+=h[i];
		}
		ave/=n;
		for(int i=1;i<=n;i++)
			if(h[i]>ave)
				ans+=h[i]-ave;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",cAse,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

