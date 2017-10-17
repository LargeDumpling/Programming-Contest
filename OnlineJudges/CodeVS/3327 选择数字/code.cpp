#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,a,head,tail;
long long s[100050][2],f,all;
int main()
{
	freopen("code.in","r",stdin);
	scanf("%d%d",&n,&k);
	head=tail=1;
	s[1][0]=s[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		all+=a;
		while(s[head][1]<i-k-1)
			head++;
		f=s[head][0]+a;
		while(s[tail][0]>f&&tail>=head)
			tail--;
		s[tail+1][0]=f;
		s[tail+1][1]=i;
		tail++;
	}
	while(s[head][1]<n-k)
		head++;
	printf("%lld",all-s[head][0]);
	return 0;
}

