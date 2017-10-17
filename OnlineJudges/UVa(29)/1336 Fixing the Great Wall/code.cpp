/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-29	File created.
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
	double pos,t,d;
	bool operator<(const jp X)const { return pos<X.pos; }
}sec[1050];
const double INF=1e30;
int n;
double f[1050][1050][2],pre[1050],sta,v;
double del(int l,int r) { return pre[r]-pre[l-1]; }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	double tem,presum,ans;
	int r;
	while(scanf("%d%lf%lf",&n,&v,&sta)!=-1&&n&&v&&sta)
	{
		pre[0]=presum=0;
		ans=INF;
		for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&sec[i].pos,&sec[i].t,&sec[i].d);
		sort(sec+1,sec+n+1);
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+sec[i].d;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j][0]=f[i][j][1]=INF;
		for(int i=1;i<=n;i++)
		{
			tem=fabs(sec[i].pos-sta)/v;
			presum+=sec[i].t;
			f[i][i][0]=f[i][i][1]=del(1,n)*tem;
		}
		for(int len=0;len<n;len++)
		{
			for(int l=1;l+len<=n;l++)
			{
				r=l+len;
				if(l>1)
				{
					tem=fabs(sec[l-1].pos-sec[l].pos)/v;
					tem=(del(1,n)-del(l,r))*tem;
					f[l-1][r][0]=min(f[l-1][r][0],f[l][r][0]+tem);
					tem=fabs(sec[l-1].pos-sec[r].pos)/v;
					tem=(del(1,n)-del(l,r))*tem;
					f[l-1][r][0]=min(f[l-1][r][0],f[l][r][1]+tem);
				}
				if(r<n)
				{
					tem=fabs(sec[r+1].pos-sec[l].pos)/v;
					tem=(del(1,n)-del(l,r))*tem;
					f[l][r+1][1]=min(f[l][r+1][1],f[l][r][0]+tem);
					tem=fabs(sec[r+1].pos-sec[r].pos)/v;
					tem=(del(1,n)-del(l,r))*tem;
					f[l][r+1][0]=min(f[l][r+1][1],f[l][r][1]+tem);
				}
			}
		}
		ans=min(f[1][n][0],f[1][n][1]);
		printf("%.0f\n",floor(ans+presum));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

