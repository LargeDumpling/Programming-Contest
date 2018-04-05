/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char S[45],A[45],B[55],C[45];
int len,lenA,lenB,cn;
int main()
{
	gets(S); len=strlen(S);
	gets(A); lenA=strlen(A);
	gets(B); lenB=strlen(B);
	for(int i=0;i<len-i-1;i++)
		swap(S[i],S[len-i-1]);
	for(int i=0;i<lenA-i-1;i++)
		swap(A[i],A[lenA-i-1]);
	for(int i=0;i<lenB-i-1;i++)
		swap(B[i],B[lenB-i-1]);
	for(int i=0;i<len;i++)
	{
		S[i]-='0';
		if(S[i]==0) S[i]=10;
	}
	S[len]=10;
	for(int i=0;i<lenA;i++)
		A[i]-='0';
	A[lenA]=0;
	for(int i=0;i<lenB;i++)
		B[i]-='0';
	B[lenB]=0;
	cn=max(lenA,lenB);
	for(int i=0;i<cn;i++)
	{
		if(20<=i) S[i]=10;
		C[i]+=A[i]+B[i];
		if(S[i]<=C[i])
		{
			if(i==cn-1) cn++;
			C[i+1]+=C[i]/S[i];
			C[i]%=S[i];
		}
	}
	while(C[cn-1]==0) cn--;
	for(int i=cn-1;0<=i;i--)
		printf("%d",C[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

