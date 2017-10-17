#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
struct Matrix
{
	int r,c;
	int M[35][35];
	Matrix()
	{
		memset(M,0,sizeof(M));
	}
	inline Matrix operator*(const Matrix X)const
	{
		Matrix C;
		C.r=r;
		C.c=X.c;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=X.c;j++)
				for(int k=1;k<=c&&k<=X.r;k++)
					C.M[i][j]=(C.M[i][j]+M[i][k]*X.M[k][j])%m;
		return C;
	}
	inline Matrix operator+(const Matrix X)const
	{
		Matrix C;
		C.r=r;
		C.c=c;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				C.M[i][j]=(M[i][j]+X.M[i][j])%m;
		return C;
	}
}E,Pow[32],ans;
Matrix solve(int x)
{
	if(x==1)return Pow[0];
	int lowbit=x&-x,h=0;
	while((1<<h)<lowbit)h++;
	if(x==lowbit)
		return solve(x>>1)*(E+Pow[h-1]);
	return solve(lowbit)+Pow[h]*solve(x-lowbit);
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	E.r=E.c=n;
	for(int i=1;i<=n;i++)
		E.M[i][i]=1%m;
	Pow[0].r=Pow[0].c=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&Pow[0].M[i][j]);
	for(int i=1;(1<<i)<=k;i++)
	{
		Pow[i].r=Pow[i].c=n;
		Pow[i]=Pow[i-1]*Pow[i-1];
	}
	ans=solve(k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%d%c",ans.M[i][j],j==n?'\n':' ');
	return 0;
}

