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
	int n=rand()%4+1;
	printf("%d\n",n);
	while(n--)
		printf("%d ",rand()%10+1);
	fclose(stdout);
	return 0;
}

