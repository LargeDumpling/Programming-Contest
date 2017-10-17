#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
using namespace std;
long long int c(int k)
{
	return k?c(k-1)*3:1;
}
long long int f(int k,int i)
{
	if(i<=0)return 0;
	if(k==0)return 1;
	long long int num=1<<(k-1);
	if(i>num)
		return f(k-1,i-num)+2*c(k-1);
	else return 2*f(k-1,i); 
}
int kk,t;
int main()
{
	freopen("code.in","r",stdin);
	freopen("HaGou.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{	
		int k,a,b;
		scanf("%d%d%d",&k,&a,&b);
		long long int ans=f(k,b)-f(k,a-1);
		printf("Case %d: %lld\n",++kk,ans);
	}
	return 0;
}

