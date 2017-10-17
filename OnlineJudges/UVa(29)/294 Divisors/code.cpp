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
int pri[35000],en[35000];
void pre_calc_pri()
{
	bool exist[35000];
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;i<35000;i++)
	{
		if(exist[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<35000;j++)
		{
			exist[i*pri[j]]=false;
			if(!(i/pri[j]))break;
		}
	}
	return;
}
int calc(int x)
{
	int ans=1;
	en[0]=0;
	for(int i=1;i<=pri[0]&&x>1;i++)if(!(x%pri[i]))
	{
		en[++en[0]]=0;
		while(!(x%pri[i]))
		{
			x/=pri[i];
			en[en[0]]++;
		}
	}
	if(x>1)ans=2;
	for(int i=1;i<=en[0];i++)ans*=(en[i]+1);
	return ans;
}
void solve(int L,int R,int &mAx,int &num)
{
	int temp;
	mAx=0;
	num=0;
	for(int i=L;i<=R;i++)
	{
		temp=calc(i);
		if(temp>num)
		{
			mAx=i;
			num=temp;
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int mAx,num;
	pre_calc_pri();
	int T,L,R;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d",&L,&R);
		solve(L,R,mAx,num);
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,R,mAx,num);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

