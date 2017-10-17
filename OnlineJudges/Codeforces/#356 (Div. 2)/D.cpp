/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-06-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long tri[100050],m,maxx=0;
int maxt=0;
void pre_calc()
{
	for(int i=1;i<=100000;i++) tri[i]=(long long)i*i*i;
	return;
}
void DFS(long long left,int k,int turn,long long X)
{
	if(left<0) return;
	else if(!left)
	{
		if(maxt<turn) maxt=turn,maxx=X;
		else if(maxt==turn) maxx=max(maxx,X);
		return;
	}
	while(left<tri[k]) k--;
	long long num=(long long)k*k*k;
	DFS(left-num,k,turn+1,X+num);
	if(k>=1)
		DFS(num-1-(long long)(k-1)*(k-1)*(k-1),k,turn+1,X+(long long)(k-1)*(k-1)*(k-1));
	//DFS(num-1LL,k-1,turn,X);
	return;
}
int main()
{
	pre_calc();
	cin>>m;
	DFS(m,100000,0,0LL);
	printf("%d %I64d",maxt,maxx);
	return 0;
}

