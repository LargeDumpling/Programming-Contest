/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int INF=2147483647;
int n,num[MAXN],low=INF;
int cnt[3];
int main()
{
	int ans=n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{ 
		scanf("%d",&num[i]);
		low=min(low,num[i]);
	}
	for(int i=1;i<=n;i++)
		cnt[num[i]-low]++;
	if(min(cnt[0],cnt[2])<cnt[1]/2&&min(cnt[0],cnt[2])!=0)
	{
		ans=cnt[1]/2;
		cnt[0]+=ans;
		cnt[2]+=ans;
		cnt[1]-=ans*2;
		ans=n-ans*2;
	}
	else
	{
		ans=min(cnt[0],cnt[2]);
		cnt[0]-=ans;
		cnt[2]-=ans;
		cnt[1]+=ans*2;
		ans=n-ans*2;
	}
	printf("%d\n",ans);
	for(int i=0;i<=2;i++)
		while(cnt[i]--)
			printf("%d ",i+low);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

