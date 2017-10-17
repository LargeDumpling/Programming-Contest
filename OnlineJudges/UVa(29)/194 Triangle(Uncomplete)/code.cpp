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
const double PI=3.1415926535;
const double eps=1e-10;
double a,b,c,al,be,ga,sinal,sinbe,singa,cosal,cosbe,cosga;
int dcmp(double x) { if(fabs(x)<eps) return 0; return x<0?-1:1; }
bool check()
{
	if(a<=0||b<=0||c<=0) return false;
	if(al<=0||be<=0||ga<=0||al>=PI||be>=PI||ge>=PI||dcmp(al+be+ga-PI))
		return false;
	if(dcmp(a*sinbe-b*sinal)
		||dcmp(a*singa-c*sinal)
		||dcmp(b*singa-c*singbe))
			return false;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,knowne,knowna;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&al,&be,&ga);
		if(al!=-1) sinal=sin(al),cosal=cos(al); else al=0;
		if(be!=-1) sinbe=sin(be),cosbe=cos(be); else be=0;
		if(ga!=-1) singa=sin(ga),cosga=cos(ga); else ga=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

