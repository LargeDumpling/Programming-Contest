/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,num[100050];
char str[100050];
bool check(int x)
{
	int sum1=0,sum2=0;
	bool ans=false,flag=true;
	for(int i=1;i<=num[0];i++)
	{
		if(i==1||i==num[0])
		{
			if(x<num[i])
				flag=false;
			if(x<(num[i]+1)/2)
				return false;
		}
		else
		{
			if(x<(num[i]+1)/2)
				flag=false;
			if(x<(num[i]/2+1)/2)
				return false;
		}
	}
	if(flag) return true;
	for(int i=1;i<num[0];i++)
	{
		if(i==1||i==num[0]-1)
		{
			if(num[i]+num[i+1]+1<=x)
				sum1++;
		}
		else if((num[i]+num[i+1]+2)/2<=x)
			sum1++;
	}
	for(int i=1;i<=num[0];i++)
	{
		if(i==1||i==num[0])
		{
			if(x<num[i]&&(num[i]+1)/3<=x)
				sum2++;
		}
		else if(x<(num[i]+1)/2&&(num[i]/2+1)/2<=x)
			sum2++;
	}
	if(sum1!=0&&sum2==1) return true;
	else if(sum1==0&&sum2==0) return true;
	sum1=sum2=0;
	for(int i=1;i<num[0];i++)
	{
		if(i==1&&i==num[0]-1)
		{
			if(x<num[i]||x<num[i+1])
			{
				sum1++;
				if((num[i]+num[i+1]+1)/2<=x)
					sum2++;
			}
		}
		else if(i==1)
		{
			if((x<num[i]||x<(num[i+1]+1)/2))
			{
				sum1++;
				if((num[i]+num[i+1]+2)/3<=x)
					sum2++;
			}
		}
		else if(i==num[0]-1)
		{
			if((x<(num[i]+1)/2||x<num[i+1]))
			{
				sum1++;
				if((num[i]+num[i+1]+2)/3<=x)
					sum2++;
			}
		}
		else if((x<(num[i]+1)/2||x<(num[i+1]+1)/2))
		{
			sum1++;
			if((num[i]+num[i+1]+1)/2<=x)
				sum2++;
		}
	}
	if(sum1<=1&&sum1==sum2) ans=true;
	return ans;
}
int main()
{
	freopen("stations.in","r",stdin);
	int last,l,mid,r;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%s",&n,str+1);
		num[0]=last=0;
		for(int i=1;i<=n+1;i++) if(str[i]=='+'||i==n+1)
		{
			num[++num[0]]=i-last-1;
			last=i;
		}
		l=-1; r=n+1;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid;
		}
		printf("%d\n",r);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

