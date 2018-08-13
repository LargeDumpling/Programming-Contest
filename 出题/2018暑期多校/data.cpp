/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long Rand()
{
	return (long long)rand()*rand()*rand();
}
int main(int argc,char *argv[])
{
	int x; sscanf(argv[1],"%d",&x); srand(x);
	freopen("Problem.in","w",stdout);
	char filename[20];
	int T_T;
	long long A,B,C,D,P,n;
	//printf("%d\n",T_T=rand()%2+1);
	printf("%d\n",T_T=20);
	while(T_T--)
	{
		/*A=rand()%3+1;
		B=rand()%3+1;
		C=rand()%3+1;
		D=rand()%3+1;
		P=rand()%5+1;
		n=rand()%5+1;*/
		A=rand()%1000000001;
		B=rand()%1000000001;
		C=rand()%1000000001;
		D=rand()%1000000001;
		P=Rand()%1000000000+1;
		n=Rand()%1000000+1;
		//P=735134400;
		//n=1000000000;
		//P=1000000000;
		//n=10000000000;
		printf("%lld %lld %lld %lld %lld %lld\n",A,B,C,D,P,n);
	}
	fclose(stdout);
	return 0;
}

