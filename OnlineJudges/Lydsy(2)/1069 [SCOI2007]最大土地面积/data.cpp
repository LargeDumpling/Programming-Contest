#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x); srand(x);
	int n=rand()%100;
	printf("%d\n",n);
	while(n--)
	{
		int a=rand()%100000,b=rand()%100000;
		if(rand()&1) a=-a;
		if(rand()&1) b=-b;
		printf("%d %d\n",a,b);
	}
	fclose(stdout);
	return 0;
}

