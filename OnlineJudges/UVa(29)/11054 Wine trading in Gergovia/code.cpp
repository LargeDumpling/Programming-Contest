#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,num;
	long long ave,ans=0;
	while(scanf("%d",&n)==1&&n)
	{
		ave=ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num);
			ans+=abs(ave);
			ave+=num;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

