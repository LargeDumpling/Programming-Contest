#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,k;
long long num[550];
bool check(long long limit)
{
	int cnt=0;
	long long sum=0;
	for(int i=1;i<=n;sum+=num[i++])
		if(sum+num[i]>limit)
		{
			cnt++;
			sum=0;
		}
	return cnt<=k;
}
void print(long long limit)
{
	int cnt=k;
	long long sum=num[n];
	bool exist[505];
	memset(exist,0,sizeof(exist));
	for(int i=n-1;i;sum+=num[i--])
		if(sum+num[i]>limit||i==cnt)
		{
			sum=0;
			exist[i]=true;
			cnt--;
		}
	for(int i=1;i<n;i++)
	{
		printf("%lld ",num[i]);
		if(exist[i])
			printf("/ ");
	}
	printf("%lld\n",num[n]);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		l=r=0;
		scanf("%d%d",&n,&k);
		k--;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			l=max(l,num[i]);
			r+=num[i];
		}
		l--;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			if(check(mid))
				r=mid;
			else
				l=mid;
		}
		print(r);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

