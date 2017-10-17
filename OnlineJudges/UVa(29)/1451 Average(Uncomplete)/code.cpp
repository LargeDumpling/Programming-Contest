#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,L,sum[100050];
double kalk(int A,int B)
{
	return (sum[B]-sum[A-1])/(B-A+1);
}
void solve()
{
	int ansa=1,ansb=L,t=1;
	for(int i=1;i<=n;i++)
	{

	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[100050];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%s",&n,&L,tex+1);
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(tex[i]=='1');
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

