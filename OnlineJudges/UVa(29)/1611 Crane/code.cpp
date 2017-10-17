/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History: 
	2015-11-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,a[10050],b[10050],ans[50000][2],an;
void sWap(int l,int r)
{
	int lenth=(r-l+1)>>1;
	for(int i=0;i<lenth;i++)
	{
		swap(a[l+i],a[l+i+lenth]);
		swap(b[a[l+i]],b[a[l+i+lenth]]);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		an=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(b[i]==i)continue;
			if((b[i]<<1)<=n+i+1)
			{
				ans[an][0]=i;
				ans[an][1]=(b[i]<<1)-i-1;
				sWap(ans[an][0],ans[an][1]);
				an++;
			}
			else
			{
				if((b[i]-i)&1)
				{
					ans[an][0]=i;
					ans[an][1]=b[i];
					sWap(ans[an][0],ans[an][1]);
					an++;
				}
				else
				{
					ans[an][0]=i+1;
					ans[an][1]=b[i];
					sWap(ans[an][0],ans[an][1]);
					an++;
				}
				ans[an][0]=i;
				ans[an][1]=(b[i]<<1)-i-1;
				sWap(ans[an][0],ans[an][1]);
				an++;
			}
		}
		printf("%d\n",an);
		for(int i=0;i<an;i++)
			printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

