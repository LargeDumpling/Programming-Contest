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
int T;
double a,b,s,m,ans;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf",&a,&b,&s);
		m=a*b;
		if(s<1e-8)ans=1;
		else if(s>m)ans=0;
		else ans=(m-s-s*log(m/s))/m;
		printf("%.6lf%%\n",ans*100);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

