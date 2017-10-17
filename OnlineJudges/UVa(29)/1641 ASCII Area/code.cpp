/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,ans=0,cnt;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[105];
	while(true)
	{
		if(scanf("%d%d",&n,&m)==-1)break;
		getchar();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cnt=0;
			gets(tex+1);
			for(int j=1;j<=m;j++)
				if(tex[j]=='/'||tex[j]=='\\'){if(cnt++&1)ans++;}
				else if(cnt&1)ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

