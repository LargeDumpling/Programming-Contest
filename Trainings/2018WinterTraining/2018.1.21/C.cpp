/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=5050;
int n,ans=0;
long long x[MAXN],y[MAXN],z[MAXN];
bool exist[MAXN];
int main()
{
	memset(exist,true,sizeof(exist));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
		if(i)
		{
			x[i]-=x[0];
			y[i]-=y[0];
			z[i]-=z[0];
		}
	}
	for(int i=1;i<n;i++) if(exist[i])
	{
		ans++;
		exist[i]=false;
		for(int j=1;j<n;j++) if(exist[j])
		{
			if(x[j]!=0&&x[i]*y[j]==y[i]*x[j]&&x[i]*z[j]==z[i]*x[j])
				exist[j]=false;
			else if(x[j]==0&&x[i]==0&&y[i]*z[j]==y[j]*z[i])
				exist[j]=false;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

