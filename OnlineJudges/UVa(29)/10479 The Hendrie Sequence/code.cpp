/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned long long f[64][64],n;
void pre_calc()
{
	for(int i=0;i<64;i++)
		f[0][i]=1;
	for(int j=1;j<64;j++)
		for(int i=0;i<64;i++)
			f[j][i]=f[j-1][0]*(unsigned long long)i+f[j-1][i+1];
	return;
}
int gEt(int st,int lev,unsigned long long rem)
{
	if(!lev) return st;
	if(rem<=f[lev-1][0]*st)
		return rem%f[lev-1][0]?gEt(0,lev-1,rem%f[lev-1][0]):gEt(0,lev-1,f[lev-1][0]);
		/*return gEt(0,lev-1,rem%(f[lev-1][0]*st)
				?rem%(f[lev-1][0]*st)
				:f[lev-1][0]*st);*/
	else return gEt(st+1,lev-1,rem-f[lev-1][0]*st);
}
int calc()
{
	int level;
	for(level=0;level<63&&(1LL<<level)<n;level++);
	if(!level) return 0;
	n-=(1LL<<(level-1));
	return gEt(0,level,n);
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	pre_calc();
	while(scanf("%lld",&n)!=-1&&n!=0)
		printf("%d\n",calc());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

