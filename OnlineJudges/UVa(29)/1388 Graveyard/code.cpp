/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
double pos1[2050],pos2[2050];
bool exist[2050];
int n,m;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int x,l,r,mid;
	double ans;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		memset(exist,false,sizeof(exist));
		for(int i=0;i<n;i++)pos1[i]=i*10000./n;
		for(int i=0;i<n+m;i++)pos2[i]=i*10000./(n+m);
		ans=0;
		x=0;
		for(int i=0;i<n;i++)
		{
			r=upper_bound(pos2,pos2+n+m,pos1[i])-pos2;
			l=r-1;
			mid=abs(pos2[l]-pos1[i])<abs(pos2[r]-pos1[i])?l:r;
			if(exist[mid])mid=l^r^mid;
			ans+=abs(pos2[mid]-pos1[i]);
			exist[mid]=true;
		}
		printf("%.4f\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

