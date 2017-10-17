#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,num[80],ans1,ans,tem;
int calc(int x)
{
	int sum=0,q=1,h=m;
	for(int i=0;i<m;i++)
		if(x&(1<<i))
			sum+=(1<<i)*num[q++];
		else
			sum+=(1<<i)*num[h--];
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			scanf("%d",&num[j]);
		ans1=0;
		for(int i=0;i<(1<<m);i++)
		{
			tem=calc(i);
			if(tem>ans1)
				ans1=tem;
		}
		ans+=ans1;
	}
	ans*=2;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
    return 0;
}

