/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-10;
int dcmp(double x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	bool valid;
	int T_T,cAse=0;
	double x,y,z,S;
	scanf("%d",&T_T);
	while(cAse<T_T)
	{
		valid=true;
		scanf("%lf%lf%lf",&x,&y,&z);
		if(!dcmp(x)||!dcmp(y)||!dcmp(z)) valid=false;
		if(valid)
		{
			x=1/x; y=1/y; z=1/z;
			if(dcmp(x+y-z)<=0||dcmp(x+z-y)<=0||dcmp(y+z-x)<=0) valid=false;
			else S=sqrt((x+y+z)*(x+y-z)*(x+z-y)*(y+z-x));
			if(valid) S=1/S;
		}
		if(valid) printf("%.3f\n",S);
		else
		{
			puts("These are invalid inputs!");
			cAse++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

