/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,ans,f[50050],d[50050];
int find(int x)
{
	while(f[x]!=f[f[x]])
	{
		d[x]=(d[x]+d[f[x]])%3;
		f[x]=f[f[x]];
	}
	return f[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int D,x,y,X,Y;
	ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) f[i]=i,d[i]=0;
	while(k--)
	{
		scanf("%d%d%d",&D,&x,&y);
		if(x>n||y>n) { ans++; continue; }
		X=find(x); Y=find(y);
		if(X==Y)
		{
			if(D-1!=(d[x]-d[y]+3)%3)
				ans++;
		}
		else
		{
			f[X]=Y;
			d[X]=(d[y]-d[x]+D+2)%3;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

