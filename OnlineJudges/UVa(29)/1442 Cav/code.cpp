#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,l[1000050],h[1000050],level[1000050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int temp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&l[i]);
		for(int i=1;i<=n;i++)scanf("%d",&h[i]);
		temp=2147483647;
		for(int i=1;i<=n;i++)
		{
			if(l[i]>temp)temp=l[i];
			if(h[i]<temp)temp=h[i];
			level[i]=temp;
		}
		temp=2147483647;
		for(int i=n;i;i--)
		{
			if(l[i]>temp)temp=l[i];
			if(h[i]<temp)temp=h[i];
			level[i]=min(level[i],temp);
		}
		temp=0;
		for(int i=1;i<=n;i++)
			if(level[i]>l[i])
				temp+=(level[i]-l[i]);
		printf("%d\n",temp);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

