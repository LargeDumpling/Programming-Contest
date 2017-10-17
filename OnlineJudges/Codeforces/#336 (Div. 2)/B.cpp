/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int lenA,lenB,num[200050];
char A[200050],B[200050];
int nUm(int L,int R) { return L?num[R]-num[L-1]:num[R]; }
int NuM(int L,int R) { return R-L+1-nUm(L,R); }
long long ans=0;
int main()
{
	int l,r;
	scanf("%s%s",A,B);
	lenA=strlen(A); lenB=strlen(B);
	num[0]=(A[0]=='1');
	for(int i=1;i<lenA;i++)num[i]=num[i-1]+(A[i]=='1');
	for(int i=0;i<lenB;i++)
	{
		r=min(i,lenA-1);
		l=max(0,lenA-lenB+i);
		if(B[i]=='1') ans+=NuM(l,r);
		else ans+=nUm(l,r);
	}
	cout<<ans;
	return 0;
}

