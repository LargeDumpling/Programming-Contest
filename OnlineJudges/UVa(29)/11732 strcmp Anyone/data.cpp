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
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	int k=rand()%10+1,lenth,n;
	while(k--)
	{
		printf("%d\n",n=rand()%40+1);
		for(int i=1;i<=n;i++)
		{
			lenth=rand()%10+1;
			for(int i=1;i<=lenth;i++)
				printf("%c",rand()%26+97);
			printf("\n");
		}
	}
	printf("0");
	fclose(stdout);
	return 0;
}

