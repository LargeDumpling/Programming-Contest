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
	int n=rand()%10000+50001;
	printf("%d\n",n);
	printf("%c",rand()%9+'1');
	for(int i=1;i<n;i++)
		printf("%c",rand()%10+'0');
	printf("\n");
	printf("%c",rand()%9+'1');
	for(int i=1;i<n;i++)
		printf("%c",rand()%10+'0');
	fclose(stdout);
	return 0;
}

