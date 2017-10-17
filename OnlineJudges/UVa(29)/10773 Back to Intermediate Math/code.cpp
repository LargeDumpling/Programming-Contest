/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T;
	double d,w,b;
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		printf("Case %d: ",cAse);
		scanf("%lf%lf%lf",&d,&w,&b);
		if(w==0||b==0||w>=b) puts("can't determine");
		else printf("%.3f\n",fabs(d/b-(d/sqrt(b*b-w*w))));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

