/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[20][1550],pri[12000];
void pre_calc_pri()
{
	bool exist[1550];
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;i<1550;i++)
	{
		if(exist[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<1550;j++)
		{
			exist[i*pri[j]]=false;
			if(!(i%pri[j]))break;
		}
	}
	return;
}
void pre_calc_f()
{
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int k=1;k<=pri[0];k++)
		for(int i=19;i;i--)
			for(int j=1549;j>=pri[k];j--)
				f[i][j]+=f[i-1][j-pri[k]];
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,k;
	pre_calc_pri();
	pre_calc_f();
	while(scanf("%d%d",&n,&k)!=-1&&n&&k)
		printf("%d\n",f[k][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

