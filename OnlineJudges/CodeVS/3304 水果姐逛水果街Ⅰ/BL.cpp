#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,num[200050],m;
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int l,r,mIn,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		ans=0;
		mIn=2147483647;
		if(l<=r)
			for(int i=l;i<=r;i++)
			{
				ans=max(ans,num[i]-mIn);
				mIn=min(mIn,num[i]);
			}
		else
			for(int i=l;i>=r;i--)
			{
				ans=max(ans,num[i]-mIn);
				mIn=min(mIn,num[i]);
			}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

