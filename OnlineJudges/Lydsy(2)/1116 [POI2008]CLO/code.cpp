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
int f[100050],size[100050],n,m;
int find(int x)
{
	while(f[x]!=f[f[x]]) f[x]=f[f[x]];
	return f[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		size[i]=-1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		x=find(a); y=find(b);
		if(x!=y)
		{
			f[x]=y;
			size[y]+=(size[x]+1);
		}
		else size[x]++;
	}
	for(int i=1;i<=n;i++)
		if(size[find(i)]<0)
		{
			printf("NIE");
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	printf("TAK");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

