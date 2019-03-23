#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int main()
{
	int T_T,n,num[MAXN],sum;
	scanf("%d",&T_T);
	for(int T=1;T<=T_T;T++)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		sort(num+1,num+n+1);
		for(int i=1;i<=n;i++)
			if(i%3==0) continue;
			else sum+=num[i];
		printf("Case #%d: %d\n",T,sum);
	}
	return 0;
}

