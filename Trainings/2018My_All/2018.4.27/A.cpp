/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct jp
{
	int data;
	jp* next;
}*head;
int T_T,n,k;
int num[MAXN];
int main()
{
	int sum,ans=0;
	scanf("%d",&T_T);
	for(int T=1;T<=T_T;T++)
	{
		scanf("%d%d",&n,&k);
		memset(num,0,sizeof(num));
		sum=ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		if(sum%k) ans=-1;
		else
		{
			sum/=k;
			for(int i=1;i<=n;i++) if(num[i])
			{
				for(int j=i+1;num[i]<sum&&j<=n;j++) if(num[j])
				{
					if(sum-num[i]<=num[j])
					{
						num[j]-=(sum-num[i]);
						num[i]=sum;
						ans++;
					}
					else if(num[j]<sum-num[i])
					{
						num[i]+=num[j];
						num[j]=0;
						ans++;
					}
				}
				if(num[i]>sum)
				{
					num[i+1]+=(num[i]-sum);
					num[i]=sum;
					if(i==n) n++;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

