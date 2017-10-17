#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[1000050];
bool cnmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1,cnmp);
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

