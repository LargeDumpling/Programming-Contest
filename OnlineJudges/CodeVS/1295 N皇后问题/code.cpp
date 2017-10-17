#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,have[14],hn,h;
long long ans=0;
void DFS(int u)
{
	if(u==n+1)
	{
		ans++;
		return;
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		if(h&(1<<(i-1)))
			continue;
		flag=true;
		for(int k=1;k<=hn;k++)
			if(abs(k-u)==abs(have[k]-i))
				flag=false;
		if(!flag)
			continue;
		h+=(1<<(i-1));
		have[++hn]=i;
		DFS(u+1);
		hn--;
		h-=(1<<(i-1));
	}
	return;
}
int main()
{
	scanf("%d",&n);
	DFS(1);
	printf("%lld",ans);
	return 0;
}

