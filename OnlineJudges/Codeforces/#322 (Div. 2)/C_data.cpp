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
	int n=rand()%5+1,k=rand()%20+1;
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%101);
	printf("\n");
    return 0;
}

