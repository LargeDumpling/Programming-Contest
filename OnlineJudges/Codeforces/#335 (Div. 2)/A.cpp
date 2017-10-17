/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int A1,B1,C1,A2,B2,C2;
int main()
{
	int temp=0;
	scanf("%d%d%d%d%d%d",&A1,&B1,&C1,&A2,&B2,&C2);
	if(A1>A2)temp+=(A1-A2)>>1;
	if(B1>B2)temp+=(B1-B2)>>1;
	if(C1>C2)temp+=(C1-C2)>>1;
	if(A1<A2)temp-=(A2-A1);
	if(B1<B2)temp-=(B2-B1);
	if(C1<C2)temp-=(C2-C1);
	if(temp<0)printf("No");
	else printf("Yes");
	return 0;
}

