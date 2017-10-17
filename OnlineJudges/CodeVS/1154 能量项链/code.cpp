#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mAx(a,b) ((a)<(b)?(b):(a))
#define R(x) (x==n+n+1?1:x)
using namespace std;
int n,num[205];
long long f[205][205];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int i,j,k;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		num[i+n]=num[i];
	}
	for(j=2;j<=n;j++)
		for(i=1;i+j<=n+n;i++)
			for(k=1;k<j;k++)
				f[i][j]=mAx(f[i][j],f[i][k]+f[i+k][j-k]+num[i]*num[i+k]*num[R(i+j)]);
	for(int i=1;i<=n;i++)
		ans=max(ans,f[i][n]);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

