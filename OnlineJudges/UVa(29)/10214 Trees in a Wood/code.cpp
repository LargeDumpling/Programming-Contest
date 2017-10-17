/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
long long pn[2050][2050];
bool prime(int a,int b)
{
	int t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a==1;
}
void pre_calc()
{
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<=i;j++)if(prime(i,j))pn[i][j]++;
		for(int j=1;j<=i;j++)pn[i][j]+=pn[i][j-1];
	}
	return;
}
void swap(long long &a,long long &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
long long calc(int a,int b)
{
	long long ans=0;
	for(int i=1;i<=a;i++)
		ans+=(b/i)*pn[i][i]+pn[i][b%i];
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long tot,all;
	pre_calc();
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		if(n>m)swap(n,m);
		all=4LL*n*m+(n<<1)+(m<<1);
		tot=calc(n,m);
		tot*=4;
		tot+=4;
		printf("%.7lf\n",(double)tot/all);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

