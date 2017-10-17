/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-07	File created.
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
	int n,m,num[105],k;
	memset(num,0,sizeof(num));
	n=rand()%5+1; m=rand()%5+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) num[i]=m;
	for(int i=1;i<n;i++)
	{
		k=rand()%5;
		if(rand()%2) k*=-1;
		num[i]+=k;
		num[i+1]-=k;
		printf("%d ",num[i]);
	}
	printf("%d",num[n]);
	fclose(stdout);
	return 0;
}

