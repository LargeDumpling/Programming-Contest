/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	const static int BASE=10000,LENTH=4;
	int num[1050],ws;
	jp()
	{
		memset(num,ws=0,sizeof(num));
	}
	jp(int nUm)
	{
		memset(num,ws=0,sizeof(num));
		if(!nUm)ws=1;
		for(;nUm;nUm/=BASE)
			num[ws++]=nUm%BASE;
	}
	jp(char tex[])
	{
		memset(num,ws=0,sizeof(num));
		int i,sum=0,lenth,teml;
		for(lenth=0;'0'<=tex[lenth]&&tex[lenth]<='9'&&tex[lenth]!='\0';lenth++);
		//for(i=(lenth>>1)-1;i>=0;i--)swap(tex[i],tex[lenth-i-1]);
		teml=lenth%LENTH;
		for(i=0;i<teml;i++)sum=(sum<<1)+(sum<<3)+tex[i]-'0';
		if(sum)
		{
			num[ws++]=sum;
			sum=0;
		}
		for(i=teml;i<lenth;i++)
		{
			sum=(sum<<1)+(sum<<3)+tex[i]-'0';
			if(!((i+1-teml)%LENTH))
			{
				num[ws++]=sum;
				sum=0;
			}
		}
		for(int i=(ws>>1)-1;i>=0;i--)swap(num[i],num[ws-i-1]);
	}
	jp operator+(const jp X)const
	{
		jp C;
		C.ws=ws>X.ws?ws:X.ws;
		for(int i=0;i<C.ws;i++)
		{
			C.num[i]+=num[i]+X.num[i];
			if(C.num[i]>=BASE)
			{
				C.num[i+1]++;
				C.num[i]-=BASE;
				if(i==C.ws-1)C.ws++;
			}
		}
		return C;
	}
	void print()
	{
		printf("%d",num[ws-1]);
		for(int i=ws-2;i>=0;i--)
			printf("%04d",num[i]);
		return;
	}
}ans[10050];
void pre_calc()
{
	ans[0]=jp(0);
	ans[1]=jp(1);
	ans[2]=jp(2);
	ans[3]=jp(4);
	ans[4]=jp(7);
	for(int i=5;i<=10000;i++)
		ans[i]=ans[i-1]+ans[i-2];
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	pre_calc();
	while(scanf("%d",&n)!=-1&&n)
	{
		ans[n].print();
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

