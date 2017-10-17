#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int num[100050],ans[100050],n,amax=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	amax=num[n];
	ans[n]=0;
	for(int i=n-1;i;i--)
	{ 
		if(num[i]>amax)
		{
			amax=num[i];
			ans[i]=0;
		}
		else
			ans[i]=amax-num[i]+1;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
    return 0;
}

