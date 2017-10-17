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
	static const int BASE=10000,LENTH=4;
	int num[1050],ws;
	jp()
	{
		memset(num,ws=0,sizeof(num));
	}
	jp(int nUm)
	{
		memset(num,ws=0,sizeof(num));
		if(!nUm)ws=1;
		for(;nUm;nUm/=BASE)num[ws++]=nUm%BASE;
	}
	jp(char tex[])
	{
		int lenth,teml,sum;
		memset(num,ws=0,sizeof(num));
		for(lenth=0;'0'<=tex[lenth]&&tex[lenth]<='9'&&tex[lenth]!='\n';lenth++);
		teml=lenth%LENTH;
		if(teml)
		{
			for(int i=sum=0;i<teml;i++)sum=(sum<<1)+(sum<<3)+tex[i]-'0';
			if(sum)num[ws++]=sum;
		}
		for(int i=sum=0;i+teml<lenth;i++)
		{
			sum=(sum<<1)+(sum<<3)+tex[i+teml]-'0';
			if(!((i+1)%LENTH))
			{
				num[ws++]=sum;
				sum=0;
			}
		}
		for(int i=(ws>>1)-1;i>=0;i--)swap(num[i],num[ws-i-1]);
	}
	void print()
	{
		printf("%d",num[ws-1]);
		for(int i=ws-2;i>=0;i--)
			printf("%04d",num[i]);
		return;
	}
	jp operator+(jp A)const
	{
		jp C;
		C.ws=ws<A.ws?A.ws:ws;
		for(int i=0;i<C.ws;i++)
		{
			C.num[i]+=num[i]+A.num[i];
			if(C.num[i]>=BASE)
			{
				C.num[i+1]++;
				C.num[i]-=BASE;
				if(i==C.ws-1)C.ws++;
			}
		}
		return C;
	}
	jp operator-(jp A)const
	{
		jp C;
		C.ws=ws<A.ws?A.ws:ws;
		for(int i=0;i<=ws;i++)
		{
			C.num[i]+=(num[i]-A.num[i]);
			if(C.num[i]<0)
			{
				C.num[i+1]--;
				C.num[i]+=BASE;
			}
		}
		while(!C.num[C.ws-1])C.ws--;
		return C;
	}
}ans[1050],one=jp(1);
void pre_calc()
{
	ans[1]=jp(0);
	for(int i=2;i<=1000;i++)
	{
		ans[i]=ans[i-1]+ans[i-1];
		if(!(i&1))
			ans[i]=ans[i]+one;
		else
			ans[i]=ans[i]-one;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	pre_calc();
	while(scanf("%d",&n)!=-1)
	{
		ans[n].print();
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

