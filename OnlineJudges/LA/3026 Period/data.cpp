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
	int k=rand()%100+1,n,lenth;
	char tex[105];
	while(k--)
	{
		lenth=rand()%100+1;
		n=lenth*(rand()%1000+1);
		for(int i=0;i<lenth;i++)
			tex[i]=rand()%26+97;
		tex[lenth]='\0';
		for(int i=1;i<=(n/lenth);i++)
			printf("%s",tex);
		printf("\n");
	}
	printf("0");
	fclose(stdout);
	return 0;
}

