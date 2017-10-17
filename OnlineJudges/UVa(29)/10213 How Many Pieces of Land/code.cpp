#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	long long num[150];
	int ws;
	jp()
	{
		memset(num,ws=0,sizeof(num));
	}
	jp(const long long &x)
	{
		memset(num,ws=0,sizeof(num));
		for(int X=x;X;X/=10)num[ws++]=X%10;
	}
	jp operator+(const jp &x)const
	{
		jp C;
		C.ws=ws<x.ws?x.ws:ws;
		for(int i=0;i<C.ws;i++)
		{
			C.num[i]+=num[i]+x.num[i];
			if(C.num[i]>=10)
			{
				C.num[i+1]+=C.num[i]/10;
				C.num[i]%=10;
				if(i==C.ws-1)C.ws++;
			}
		}
		return C;
	}
	jp operator*(const long long &x)const 
	{
		jp C;
		C.ws=ws;
		for(int i=0;i<C.ws;i++)C.num[i]=num[i]*x;
		for(int i=0;i<C.ws;i++)
		{
			if(C.num[i]>=10)
			{
				C.num[i+1]+=C.num[i]/10;
				C.num[i]%=10;
				if(i==C.ws-1)C.ws++;
			}
		}
		return C;
	}
}ans,tem1,tem2;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T,n,two,three;
	long long tem[6];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==0)printf("1\n");
		else if(n==1)printf("1\n");
		else if(n==2)printf("2\n");
		else if(n==3)printf("4\n");
		else if(n==4)printf("8\n");
		else
		{
			ans=tem1=tem2=jp(1LL);
			tem[0]=n;tem[1]=n-1;tem[2]=n-2;tem[3]=n-3;tem[4]=n;tem[5]=n-1;
			two=3;three=1;
			for(int i=0;i<=3&&two;i++)while(!(tem[i]&1)&&two)tem[i]>>=1,two--;
			for(int i=0;i<=3&&three;i++)if(!(tem[i]%3)&&three)tem[i]/=3,three--;
			two=1;
			for(int i=4;i<=5&&two;i++)if(!(tem[i]&1))tem[i]>>=1,two--;
			for(int i=0;i<=3;i++)
				tem1=tem1*tem[i];
			for(int i=4;i<=5;i++)tem2=tem2*tem[i];
			ans=ans+tem1;
			ans=ans+tem2;
			for(int i=ans.ws-1;i>=0;i--)printf("%c",(int)ans.num[i]+'0');
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

