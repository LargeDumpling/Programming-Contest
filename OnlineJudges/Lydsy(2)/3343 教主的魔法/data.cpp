/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	//int N=rand()%1000+1,Q=rand()%1000+1;
	int N=1000000,Q=3000;
	printf("%d %d\n",N,Q);
	for(int i=1;i<=N;i++) printf("%d ",rand()%1000+1); putchar('\n');
	while(Q--)
	{
		int k=rand()%2,l,r;
		l=(1LL*rand()*rand())%N+1; r=(1LL*rand()*rand())%N+1;
		if(l>r) swap(l,r);
		if(k) printf("M %d %d %d\n",l,r,rand()%1001);
		//else printf("A %d %d %d\n",l,r,rand());
		else printf("A %d %d %d\n",l,r,(1LL*rand()*rand())%1000000000);
	}
	fclose(stdout);
	return 0;
}

