#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,num[100050];
int check(int T)
{
	int ans=0,left=0;
	for(int i=1;i<=n;i++)
	{
		left+=T;
		if(num[i]<left)
		{
			left-=num[i];
			ans++;
		}
		else
			left=0;
	}
	return ans>(n/2);
}
int main()
{
	int l,mid,r;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	l=1;r=k+1;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%d",check(r)?r:l);
	return 0;
}

