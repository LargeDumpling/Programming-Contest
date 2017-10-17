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
int pri[100050],n;
void pre_calc_pri()
{
	bool exist[1300050];
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;pri[0]<=100000;i++)
	{
		if(exist[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<1300000;j++)
		{
			exist[i*pri[j]]=false;
			if(!(i%pri[j]))break;
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	pre_calc_pri();
	int pos;
	while(scanf("%d",&n)!=-1&&n)
	{
		pos=upper_bound(pri+1,pri+pri[0]+1,n)-pri;
		if(pri[pos-1]==n)
			printf("0\n");
		else
			printf("%d\n",pri[pos]-pri[pos-1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

