#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,pro[20];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long mAx,t;
	for(int cAse=1;scanf("%d",&n)!=-1;cAse++)
	{
		pro[0]=1;
		mAx=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&pro[i]);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				t=1;
				for(int k=i;k<=j;k++)
					t*=pro[k];
				mAx=max(mAx,t);
			}
		printf("Case #%d: The maximum product is %lld.\n\n",cAse,mAx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

