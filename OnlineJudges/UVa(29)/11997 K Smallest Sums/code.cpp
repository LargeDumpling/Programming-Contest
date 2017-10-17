/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct jp
{
	int fir,sec;
	jp(int A=0,int B=0):fir(A),sec(B){}
	bool operator<(const jp &X)const{return fir==X.fir?sec>X.sec:fir>X.fir;}
};
int A[1000],B[1000],k;
void merge()
{
	priority_queue<jp>q;
	for(int i=1;i<=k;i++)q.push(jp(A[i]+B[1],1));
	jp tem;
	for(int i=1;i<=k;i++)
	{
		tem=q.top();
		q.pop();
		A[i]=tem.fir;
		if(tem.sec+1<=k)q.push(jp(tem.fir-B[tem.sec]+B[tem.sec+1],tem.sec+1));
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d",&k)!=-1)
	{
		for(int i=1;i<=k;i++)scanf("%d",&A[i]);
		sort(A+1,A+k+1);
		for(int i=1;i<k;i++)
		{
			for(int j=1;j<=k;j++)scanf("%d",&B[j]);
			sort(B+1,B+k+1);
			merge();
		}
		for(int i=1;i<=k;i++)printf("%d%c",A[i],i==k?'\n':' ');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

