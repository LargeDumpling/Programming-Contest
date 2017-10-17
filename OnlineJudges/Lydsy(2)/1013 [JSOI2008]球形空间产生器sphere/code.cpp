#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
double a[2][15],f[15][15];
void swap(double &a,double &b){a+=b;b=a-b;a-=b;return;}
//double abs(double x){return (x<0)?-x:x;}
void gauss()
{
	int t,i,j,k;
	double r;
	for(i=0;i<n;i++)
	{
		for(j=i+1,t=i;j<n;j++)if(abs(f[t][i])<abs(f[j][i]))t=j;
		if(t!=i)for(j=0;j<=n;j++)swap(f[i][j],f[t][j]);
		/*for(j=i+1;j<n;j++)
			for(k=i,r=f[j][i]/f[i][i];k<=n;k++)
				f[j][k]-=f[i][k]*r;*/
		for(j=n;j>=i;j--)
			for(k=i+1;k<n;k++)
				f[k][j]-=f[i][j]*f[k][i]/f[i][i];
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=i+1;j<n;j++)
			f[i][n]-=f[j][n]*f[i][j];
		f[i][n]/=f[i][i];
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int now=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lf",&a[0][i]);
	for(int i=0;i<n;i++)
	{
		now^=1;
		for(int j=0;j<n;j++)
		{
			scanf("%lf",&a[now][j]);
			f[i][j]+=2*(a[now][j]-a[now^1][j]);
			f[i][n]+=(a[now][j]*a[now][j]-a[now^1][j]*a[now^1][j]);
		}
	}
	gauss();
	for(int i=0;i<n;i++)
	{
		printf("%.3f",f[i][n]);
		if(i!=n-1)
			printf(" ");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

