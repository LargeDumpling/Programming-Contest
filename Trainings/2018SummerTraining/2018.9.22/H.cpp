/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,k;
double x[105],y[105],c[105],r;
bool neg[105];
void calc()
{
	bool flag=true;
	double dif,sum=0;
	for(int i=1;i<=k;i++)
	{
		neg[i]=(x[i]<0);
		if(neg[i]) x[i]=-x[i];
		sum+=x[i];
	}
	while(flag)
	{
		flag=false;
		dif=(sum-r)/k;
		sum=0;
		for(int i=1;i<=k;i++)
		{
			y[i]=x[i]-dif;
			if(y[i]<0)
			{
				flag=true;
				x[i]=x[i]-y[i];
				y[i]=0;
			}
			sum+=x[i];
		}
	}
	for(int i=1;i<=k;i++) if(neg[i])
		y[i]=-y[i];
	return;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%lf",&r);
		for(int i=1;i<=k;i++)
			scanf("%lf",&c[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				scanf("%lf",&x[j]);
				x[j]-=c[j];
			}
			calc();
			for(int j=1;j<=k;j++)
				printf("%lf%c",c[j]+y[j],j==k?'\n':' ');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

