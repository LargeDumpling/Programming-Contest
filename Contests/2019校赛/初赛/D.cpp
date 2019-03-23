/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-03-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
struct Mie
{
	long long num[2][2];
	Mie() { memset(num,0,sizeof(num)); }
	Mie operator*(const Mie &M)const
	{
		Mie ans;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
					ans.num[i][j]+=num[i][k]*M.num[k][j];
				ans.num[i][j]%=mod;
			}
		return ans;
	}
}C,I;
int T_T,n;
long long M2,M1,a,b;
Mie pOw(Mie X,int m)
{
	Mie ans;
	for(ans=I;m;m>>=1,X=X*X)
		if(m&1)
			ans=ans*X;
	return ans;
}
int main()
{
	I.num[0][0]=I.num[1][1]=1;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%lld%lld",&n,&a,&b);
		C.num[0][0]=(a+b)%mod;
		C.num[0][1]=(mod-a*b%mod)%mod;
		C.num[1][0]=1;
		C.num[1][1]=0;
		M1=(a+b)%mod;
		M2=(a*a+a*b+b*b)%mod;
		if(n==1) printf("%lld\n",M1);
		else
		{
			Mie M=pOw(C,n-2);
			printf("%lld\n",(M2*M.num[0][0]+M1*M.num[0][1])%mod);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

