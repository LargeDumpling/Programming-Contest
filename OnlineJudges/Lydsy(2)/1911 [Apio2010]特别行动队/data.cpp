/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long Rand() { return 1LL*rand()*rand()*rand()%2147483648LL; }
int main(int argc,char *argv[])
{
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x); srand(x);
	int n=rand()%1000+1,a;
	//n=rand()%5+1;
	long long b,c;
	a=-1*(rand()%5+1);
	b=Rand()%10000000;
	if(rand()&1) b=-b;
	c=Rand()%10000000;
	if(rand()&1) c=-c;
	printf("%d\n%d %lld %lld\n",n,a,b,c);
	while(n--) printf("%d ",rand()%100+1);
	fclose(stdout);
	return 0;
}

