#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
struct jp
{
	double x,y,z,r;
}b[7];
int n,ord[7];
double ans=0,xl,yl,zl,anst,xx,yy,zz;
bool exist[7];
void DFS(int u)
{
	if(u==n+1)
	{
		anst=0;
		for(int i=1;i<=n;i++)
		{
			b[i].r=2147483647;
			b[i].r=min(min(b[i].r,min(b[i].x,xl-b[i].x)),min(min(b[i].y,yl-b[i].y),min(b[i].z,zl-b[i].z)));
			for(int j=1;j<i;j++)
				b[i].r=min(b[i].r,sqrt((b[i].x-b[j].x)*(b[i].x-b[j].x)+(b[i].y-b[j].y)*(b[i].y-b[j].y)+(b[i].z-b[j].z)*(b[i].z-b[j].z))-b[i].r);
			anst+=4.188790204666667*b[i].r*b[i].r*b[i].r;
		}
		ans=max(ans,anst);
		return;
	}
	int suit;
	for(suit=1;suit<=n&&exist[suit];suit++);
	exist[suit]=true;
	DFS(u+1);
	exist[suit]=false;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int CASE=1;;CASE++)
	{
		scanf("%d%lf%lf%lf%lf%lf%lf",&n,&xx,&yy,&zz,&xl,&yl,&zl);
		if(!n)
			break;
		xl-=xx;
		yl-=yy;
		zl-=zz;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf",&b[i].x,&b[i].y,&b[i].z);
			b[i].x-=xx;
			b[i].y-=yy;
			b[i].z-=zz;
		}
		ans=0;
		DFS(1);
		printf("Box %d: %.0f\n\n",CASE,xl*yl*zl-ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

