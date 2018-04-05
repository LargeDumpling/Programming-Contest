#include<cstdio>
const int MAXN=1050;
int cnt[MAXN],n;
int main()
{
	int fn,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&fn);
		while(fn--)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
	}
	for(int i=x=1;i<=1000;i++)
		if(cnt[x]<=cnt[i])
			x=i;
	printf("%d %d",x,cnt[x]);
	return 0;
}

