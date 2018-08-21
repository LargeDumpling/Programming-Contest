/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=1000000050;
struct jz
{
	int f,s;
	jz(const int &F=0,const int &S=0):f(F),s(S) { }
	bool operator<(const jz &X)const { return f==X.f?s<X.s:f<X.f; }
};
int T_T,n[2];
int A[2][3];
int cmp()
{
	jz X[4];
	X[0]=jz(A[0][0],INF);
	X[1]=jz(A[0][1],A[0][2]);
	X[2]=jz(A[1][0],INF);
	X[3]=jz(A[1][1],A[1][2]);
	if(X[1]<X[0]) swap(X[0],X[1]);
	if(X[3]<X[2]) swap(X[2],X[3]);
	if(X[0]<X[2]) return 1;
	if(X[2]<X[0]) return -1;
	if(X[1]<X[3]) return 1;
	if(X[3]<X[1]) return -1;
	return 0;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n[0],&n[1]);
		for(int k=0;k<2;k++)
		{
			for(int i=0;i<n[k];i++)
			{
				scanf("%d",&A[k][i]);
				A[k][i]+=(2-i);
			}
			for(int i=n[k];i<3;i++)
				A[k][i]=INF;
			if(A[k][2]<A[k][1])
				swap(A[k][1],A[k][2]);
		}
		switch(cmp())
		{
			case -1:
				puts("-1");
				break;
			case 0:
				puts("0");
				break;
			case 1:
				puts("1");
				break;
			default:
				break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

