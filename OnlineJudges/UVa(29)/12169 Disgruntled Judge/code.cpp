/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=10001;
int T,num[20050];
void calc_T()
{
	for(int a=0,b,flag;a<=10000;a++)
		for(b=0;b<=10000;b++)
		{
			flag=true;
			for(int i=2;i<=(T<<1);i++)
			{
				if((i&1)&&(num[i-1]*a+b)%mod!=num[i]){flag=false;break;}
				else if(!(i&1))num[i]=(a*num[i-1]+b)%mod;
			}
			if(flag)return;
		}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	for(int i=0;i<T;i++)scanf("%d",&num[(i<<1)+1]);
	calc_T();
	for(int i=1;i<=T;i++)printf("%d\n",num[i<<1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

