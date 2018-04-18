/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=105;
struct jz
{
	int x,y,t;
	bool operator<(const jz &X)const { return y<X.y; }
}p[MAXN];
int nr,nc,n,m;
int hx[MAXN],hy[MAXN],ans=2147483647;
int main()
{
	scanf("%d%d%d%d",&nr,&nc,&n,&m);
	int w,b;
	//nr-=7; nc-=4;
	hx[0]=hy[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i].x);
		hx[++hx[0]]=p[i].x;
		scanf("%d",&p[i].y);
		hy[++hy[0]]=p[i].y;
		p[i].t=0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&p[n+i].x);
		hx[++hx[0]]=p[n+i].x;
		scanf("%d",&p[n+i].y);
		hy[++hy[0]]=p[n+i].y;
		p[n+i].t=1;
	}
	sort(hx+1,hx+hx[0]+1);
	hx[0]=unique(hx+1,hx+hx[0]+1)-hx-1;
	sort(hy+1,hy+hy[0]+1);
	hy[0]=unique(hy+1,hy+hy[0]+1)-hy-1;
	sort(p+1,p+n+m+1);
	for(int i=1;i<=n+m;i++)
	{
		p[i].x=lower_bound(hx+1,hx+hx[0]+1,p[i].x)-hx;
		p[i].y=lower_bound(hy+1,hy+hy[0]+1,p[i].y)-hy;
	}
	for(int i=1;i<=hx[0];i++)
	{
		for(int j=i;j<=hx[0];j++)
		{
			for(int k=1;k<=hy[0];k++)
			{
				w=b=0;
				for(int l=1;l<=n+m;l++)
				{
					if(p[l].x<i||j<p[l].x||p[l].y<k) continue;
					if(p[l].t==0) b++;
					else w++;
					if((l==n+m||p[l].y!=p[l+1].y)
							&&m*135<=nr*nc-(hx[j]-hx[i]+15)*(hy[p[l].y]-hy[k]+9)
							&&b*135<=(hx[j]-hx[i]+15)*(hy[p[l].y]-hy[k]+i))
						ans=min(ans,n-b+w);
				}
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

