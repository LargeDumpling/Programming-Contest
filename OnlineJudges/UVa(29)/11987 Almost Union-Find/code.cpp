/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[200000],size[200000],sum[200000],to[100000],sz;
int find(int x)
{
	while(f[x]!=f[f[x]]) f[x]=f[f[x]];
	return f[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,m,a,b,c,x,y;
	while(scanf("%d%d",&n,&m)!=-1&&n&&m)
	{
		for(int i=(n<<1)-1;i>=0;i--) f[i]=sum[i]=i,size[i]=1;
		for(int i=0;i<n;i++) to[i]=i;
		sz=n;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a);
			if(a==1)
			{
				scanf("%d%d",&b,&c);// b=to[b-1]; c=to[c-1];
				x=find(to[b-1]); y=find(to[c-1]);
				if(x==y) continue;//如果在一个集合则不操作，否则会加很多size和sum
				f[y]=x;
				size[x]+=size[y];
				sum[x]+=sum[y];
			}
			else if(a==2)
			{
				scanf("%d%d",&b,&c);
				x=find(to[b-1]); y=find(to[c-1]);
				if(x==y) continue;//同上
				size[x]--; sum[x]-=(b-1);//留下一个替身
				size[y]++; sum[y]+=(b-1);
				to[b-1]=sz;
				f[sz++]=y;
			}
			else if(a==3)
			{
				scanf("%d",&b); x=find(to[b-1]);
				printf("%d %d\n",size[x],size[x]+sum[x]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

