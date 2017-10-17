#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,num[4][4050];
long long a[16000050];
long long ans;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int p;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		a[0]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=0;j<4;j++)
				scanf("%d",&num[j][i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[++a[0]]=num[0][i]+num[1][j];
		sort(a+1,a+a[0]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				p=num[2][i]+num[3][j];
				p=-p;
				ans+=upper_bound(a+1,a+a[0]+1,p)-lower_bound(a+1,a+a[0]+1,p);
			}
		printf("%lld",ans);
		if(T)
			printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

