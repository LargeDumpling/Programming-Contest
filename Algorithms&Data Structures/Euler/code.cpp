#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int prime[100050],pn=-1,limit;
void Euler(int n)
{
	bool flag[n+1];
	memset(flag,true,sizeof(flag));
	for(int i=2;i<=n;i++)
	{
		if(flag[i])
			prime[++pn]=i;
		for(int j=0;j<=pn;j++)
		{
			if(i*prime[j]>n)
				break;
			flag[i*prime[j]]=false;
			if(!i%prime[j])
				break;
		}
	}
}
int main()
{
	scanf("%d",&limit);
	if(limit)
	{
		Euler(limit);
		for(int i=0;i<=pn;i++)
			printf("%d ",prime[i]);
	}
	return 0;
}

