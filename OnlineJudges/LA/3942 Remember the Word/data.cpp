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
	int times=rand()%100+1,lenth,n;
	for(int i=1;i<=times;i++)
	{
		lenth=(rand()*rand())%300+1;
		for(int i=1;i<=lenth;i++)
			printf("%c",rand()%26+97);
		printf("\n%d\n",n=(rand()%40+1));
		for(int i=1;i<=n;i++)
		{
			lenth=rand()%10+1;
			for(int i=1;i<=lenth;i++)
				printf("%c",rand()%26+97);
			printf("\n");
		}
	}
	fclose(stdout);
	return 0;
}

