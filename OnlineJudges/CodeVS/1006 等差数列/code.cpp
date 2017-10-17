/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[105];
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int cnt=0,ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt=2;
			for(int k=j+1;k<=n;k++)
			{
				if(num[k]==num[i]+cnt*(num[j]-num[i]))
					cnt++;
			}
			ans=max(ans,cnt);
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

