#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double x[2050],y[2050],ans;
double Cross(int p1,int p2,int p3)
{
	return (x[p1]-x[p3])*(y[p2]-y[p3])-(y[p1]-y[p3])*(x[p2]-x[p3]); }
double calc(int p1,int p2,int p3,int p4)
{ return (fabs(Cross(p1,p3,p2))+fabs(Cross(p1,p3,p4)))/2.; }
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					ans=max(ans,calc(i,j,k,l));
	printf("%.3f",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

