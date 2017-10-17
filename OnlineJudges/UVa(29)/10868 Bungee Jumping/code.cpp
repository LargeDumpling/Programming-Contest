/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-30	File created.
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
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	double k,l,s,w,W;
	while(true)
	{
		scanf("%lf%lf%lf%lf",&k,&l,&s,&w);
		if(k==0&&l==0&&s==0&&w==0) break;
		if(s<=l)
		{
			if(2.*9.81*s<=100.) puts("James Bond survives.");
			else puts("Killed by the impact.");
		}
		else
		{
			W=9.81*w*s-0.5*k*(s-l)*(s-l);
			if(W<0) puts("Stuck in the air.");
			else if(2.*W/w<=100.) puts("James Bond survives.");
			else puts("Killed by the impact.");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

