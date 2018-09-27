/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define low(x) ((x)&(-x))
const int MAXN=100050;
int d[MAXN];
void add(int p,int x)
{
	for(;p<MAXN;p+=low(p))
		d[p]+=x;
	return;
}
int query(int x)
{
	int sum=0;
	for(;x;x-=low(x))
		sum+=d[x];
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

