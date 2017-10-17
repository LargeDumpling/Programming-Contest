/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int loc,cost,del;
	bool operator<(const jp &X)const { return loc<X.loc; }
}dam[1050];
int n,v,x;
int pre[1050];
double f[1050][1050][2],ans;
double get_time(int i,int j) { return fabs(dam[j].loc-dam[i].loc)/v; }
double get_inc(int i,int j) { return pre[n]-pre[j]+pre[i-1]; }
void prepare()
{
	ans=0;
	memset(pre,0,sizeof(pre));
	for(int i=0;i<1050;i++)
		for(int j=0;j<1050;j++)
			f[i][j][0]=f[i][j][1]=-1;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+dam[i].del;
		ans+=dam[i].cost;
	}
	return;
}
double F(int l,int r,int sta)
{
	if(f[l][r][sta]!=-1) return f[l][r][sta];
	if(l==r) return f[l][r][sta]=1.*fabs(x-dam[l].loc)/v*pre[n];
	f[l][r][sta]=2147483647;
	if(!sta)
		f[l][r][0]=min(F(l+1,r,0)+get_inc(l+1,r)*fabs(dam[l+1].loc-dam[l].loc)/v
				      ,F(l+1,r,1)+get_inc(l+1,r)*fabs(dam[r].loc-dam[l].loc)/v);
	else
		f[l][r][1]=min(F(l,r-1,1)+get_inc(l,r-1)*fabs(dam[r].loc-dam[r-1].loc)/v
				      ,F(l,r-1,0)+get_inc(l,r-1)*fabs(dam[r].loc-dam[l].loc)/v);
	return f[l][r][sta];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("again.out","w",stdout);
	while(scanf("%d%d%d",&n,&v,&x)!=-1&&(n||v||x))
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&dam[i].loc,&dam[i].cost,&dam[i].del);
		sort(dam+1,dam+n+1);
		prepare();
		ans+=min(F(1,n,0)
				,F(1,n,1));
		printf("%.0f\n",floor(ans));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

