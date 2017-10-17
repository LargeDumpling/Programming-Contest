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
	int T=rand()%10,lenth;
	printf("%d\n",T);
	while(T--)
	{
		lenth=rand()%10+1;
		for(int i=1;i<=lenth;i++)
			printf("%c",rand()%3+'A');
		printf("\n");
	}
	fclose(stdout);
	return 0;
}

