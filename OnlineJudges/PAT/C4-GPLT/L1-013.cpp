#include<cstdio>
long long s[15];
int n;
int main()
{
	scanf("%d",&n);
	s[0]=1;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]*i;
	for(int i=2;i<=n;i++)
		s[i]+=s[i-1];
	printf("%lld",s[n]);
	return 0;
}

