/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long double ln[200050];
void pre()
{
	for(int i=1;i<=200000;i++)ln[i]=ln[i-1]+log(i);
	return;
}
double C(int m,int n){return ln[m]-ln[n]-ln[m-n];}
double solve(int n,double p)
{
	long double p1=log(p),p2=log(1-p),ans=0,v1,v2,c;
	for(int i=0;i<=n;i++)
	{
		c=C((n<<1)-i,n);
		v1=c+(n+1)*p1+(n-i)*p2;
		v2=c+(n+1)*p2+(n-i)*p1;
		ans+=i*(exp(v1)+exp(v2));
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	pre();
	int n;
	double p;
	for(int cAse=1;scanf("%d%lf",&n,&p)!=-1;cAse++)
		printf("Case %d: %.6lf\n",cAse,solve(n,p));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

