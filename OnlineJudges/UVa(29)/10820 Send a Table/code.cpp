/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int y[50050],n;
void pre_y()
{
	int pri[50050];
	bool exist[50050];
	memset(exist,true,sizeof(exist));
	int t;
	pri[0]=0;
	for(int i=2;i<=50000;i++)
	{
		if(exist[i])pri[++pri[0]]=i,y[i]=i-1;
		for(int j=1;j<=pri[0]&&(t=i*pri[j])<=50000;j++)
		{
			exist[t]=false;
			if(i%pri[j])y[t]=y[i]*(pri[j]-1);
			else
			{
				y[t]=y[i]*pri[j];
				break;
			}
		}
	}
	for(int i=2;i<=50000;i++)y[i]+=y[i-1];
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	pre_y();
	while(scanf("%d",&n)==1&&n)printf("%d\n",y[n]<<1|1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

