/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
const double eps=1e-8;
typedef double Matrix[MAXN][MAXN];
void Gauss_Jordan_Elimination(Matrix A,int n)
{
	int i,j,k,r;
	for(i=0;i<n;i++)
	{
		r=i;
		for(j=i+1;j<n;j++)
		{
			if(abs(A[j][i]>fabs(A[r][i]))) r=j;
			//if(fabs(A[r][i])<eps) continue;
			if(r!=i) for(int j=0;j<=n;j++)
				swap(A[r][j],A[i][j]);
		}
		for(k=0;k<n;k++) if(k!=i)
			for(int j=n;j>=i;j--)
				A[k][j]-=A[k][i]/A[i][i]*A[i][j];
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

