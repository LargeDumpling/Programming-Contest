/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int pre[20050],f[20050],d[20050],T,n;
int find(int x)
{
	while(f[x]!=f[f[x]])
	{
		d[x]+=d[f[x]];
		f[x]=f[f[x]];
	}
	return f[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	char tex[5];
	scanf("%d",&T);
	for(int i=0;i<20050;i++)pre[i]=i;
	while(T--)
	{
		memcpy(f,pre,sizeof pre);
		memset(d,0,sizeof(d));
		scanf("%d",&n);
		while(true)
		{
			scanf("%s",tex);
			if(tex[0]=='O')break;
			switch(tex[0])
			{
				case 'E':
					scanf("%d",&a);find(a);
					printf("%d\n",d[a]);
					break;
				case 'I':
					scanf("%d%d",&a,&b);
					f[a]=b;
					d[a]=abs(a-b)%1000;
					break;
				default:
					break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

